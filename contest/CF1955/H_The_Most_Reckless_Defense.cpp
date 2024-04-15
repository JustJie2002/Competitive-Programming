/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 17:13:25
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    static string nxt() {
        scanf("%s", buf);
        return buf;
    }
    static char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    static string lxt() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;

using i64 = long long;
using Pos = array<int, 2>;

// Warning: flow_t and cost_t must be able to handle the sums of flows and costs, not just individual edges.
template<typename flow_t, typename cost_t>
struct min_cost_flow {
    const cost_t COST_INF = numeric_limits<cost_t>::max() / 2;

    struct edge {
        int node, rev;
        flow_t capacity;
        cost_t cost;

        edge() {}

        edge(int _node, int _rev, flow_t _capacity, cost_t _cost)
            : node(_node), rev(_rev), capacity(_capacity), cost(_cost) {}
    };

    int V = -1, E = 0;
    vector<vector<edge>> adj;
    vector<cost_t> dist;
    vector<int> prv;
    vector<edge*> prev_edge;
    bool too_much_bellman_ford = false;

    min_cost_flow(int vertices = -1) {
        if (vertices >= 0)
            init(vertices);
    }

    void init(int vertices) {
        V = vertices;
        E = 0;
        adj.assign(V, {});
        dist.resize(V);
        prv.resize(V);
        prev_edge.resize(V);
        too_much_bellman_ford = false;
    }

    void add_directional_edge(int u, int v, flow_t capacity, cost_t cost) {
        assert(0 <= min(u, v) && max(u, v) < V);
        assert(capacity >= 0);
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), capacity, cost);
        edge vu_edge(u, int(adj[u].size()), 0, -cost);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
        E++;
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    bool bellman_ford(int source, int sink) {
        dist.assign(V, COST_INF);
        prv.assign(V, -1);
        prev_edge.assign(V, nullptr);

        int64_t work = 0;
        vector<int> last_seen(V, -1);
        vector<int> nodes = {source}, next_nodes;
        dist[source] = 0;

        for (int iteration = 0; iteration < V; iteration++) {
            next_nodes.clear();

            for (int node : nodes) {
                for (edge &e : adj[node])
                    if (e.capacity > 0 && dist[node] + e.cost < dist[e.node]) {
                        dist[e.node] = dist[node] + e.cost;
                        prv[e.node] = node;
                        prev_edge[e.node] = &e;

                        if (last_seen[e.node] != iteration) {
                            last_seen[e.node] = iteration;
                            next_nodes.push_back(e.node);
                        }
                    }

                work += adj[node].size();
            }

            swap(nodes, next_nodes);
        }

        if (work > 1.75L * E * (V == 0 ? 0 : 32 - __builtin_clz(V)) + 100) {
            too_much_bellman_ford = true;
            return false;
        }

        return prv[sink] != -1;
    }

    struct dijkstra_state {
        cost_t dist;
        int node;

        dijkstra_state() {}

        dijkstra_state(cost_t _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const dijkstra_state &other) const {
            return dist > other.dist;
        }
    };

    void dijkstra_check(priority_queue<dijkstra_state> &pq, int node, cost_t new_dist, int previous, edge *previous_edge) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            prv[node] = previous;
            prev_edge[node] = previous_edge;
            pq.emplace(dist[node], node);
        }
    }

    bool dijkstra(int source, int sink) {
        dist.assign(V, COST_INF);
        prv.assign(V, -1);
        prev_edge.assign(V, nullptr);

        priority_queue<dijkstra_state> pq;
        dijkstra_check(pq, source, 0, -1, nullptr);

        while (!pq.empty()) {
            dijkstra_state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                if (e.capacity > 0)
                    dijkstra_check(pq, e.node, top.dist + e.cost, top.node, &e);
        }

        return prv[sink] != -1;
    }

    void reduce_cost() {
        for (int i = 0; i < V; i++)
            for (edge &e : adj[i])
                if (dist[i] < COST_INF && dist[e.node] < COST_INF)
                    e.cost += dist[i] - dist[e.node];
    }

    pair<flow_t, cost_t> solve_min_cost_flow(int source, int sink, flow_t flow_goal = numeric_limits<flow_t>::max()) {
        assert(V >= 0);
        flow_t total_flow = 0;
        cost_t total_cost = 0;
        cost_t reduce_sum = 0;

        auto process_path = [&]() -> void {
            flow_t path_cap = flow_goal - total_flow;
            cost_t cost_sum = 0;

            for (int node = sink; prv[node] != -1; node = prv[node])
                path_cap = min(path_cap, prev_edge[node]->capacity);

            for (int node = sink; prv[node] != -1; node = prv[node]) {
                edge *e = prev_edge[node];
                e->capacity -= path_cap;
                reverse_edge(*e).capacity += path_cap;
                cost_sum += e->cost;
            }

            total_flow += path_cap;
            total_cost += (reduce_sum + cost_sum) * path_cap;
        };

        while (total_flow < flow_goal && bellman_ford(source, sink))
            process_path();

        if (too_much_bellman_ford) {
            do {
                reduce_cost();
                reduce_sum += dist[sink];
                process_path();
            } while (total_flow < flow_goal && dijkstra(source, sink));
        }

        return make_pair(total_flow, total_cost);
    }
};


void workout(int tc) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<string> board(n);
    generate(board.begin(), board.end(), fs.nxt);

    vector<Pos> bad;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {
                bad.push_back({i, j});
            }
        }
    }

    int n = sz(s);
    
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie