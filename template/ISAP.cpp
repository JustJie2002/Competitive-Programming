
constexpr int MAX_N = 1e6 + 1, inf = 1e9 + 5;
struct ISAP {
    struct Edge {
        int from, to, cap, flow;
        Edge(int _from, int _to, int _cap, int _flow): from(_from), to(_to), cap(_cap), flow(_flow) {}
        bool operator<(const Edge& o) {
            return make_pair(from, to) < make_pair(o.from, o.to);
        }
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> adj[MAX_N];
    bool vis[MAX_N];
    int d[MAX_N], cur[MAX_N], p[MAX_N], num[MAX_N];

    void init(int n) {
        this->n = n;
        m = 0;
        edges.clear();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            d[i] = cur[i] = p[i] = num[i] = vis[i] = 0;
        }
    }
    void add_edge(int from, int to, int cap) {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, cap, 0);
        m += 2;
        adj[from].push_back(m - 2);
        adj[to].push_back(m - 1);
    }

    inline bool BFS() {
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < adj[x].size(); i++) {
                Edge& e = edges[adj[x][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }
    inline int Augment() {
        int x = t, a = inf;
        while (x != s) {
            auto& e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s) {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }
    inline int work(int s, int t) {
        this->s = s;
        this->t = t;
        int flow = 0;
        BFS();
        for (int i = 0; i < n; i++) {
            num[d[i]]++;
        }
        int x = s;
        while (d[s] < n) {
            if (x == t) {
                flow += Augment();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < adj[x].size(); i++) {
                Edge& e = edges[adj[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1) {
                    ok = 1;
                    p[e.to] = adj[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if (!ok) {
                int m = n - 1;
                for (int i = 0; i < adj[x].size(); i++) {
                    Edge& e = edges[adj[x][i]];
                    if (e.cap > e.flow) m = min(m, d[e.to]);
                }
                if (--num[d[x]] == 0) break;
                num[d[x] = m + 1]++;
                cur[x] = 0;
                if (x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }
} isap;
