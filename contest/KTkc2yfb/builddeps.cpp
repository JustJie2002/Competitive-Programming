/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 21:08:08
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}
string lxt() {
    fgets(buf, BUFSIZE, stdin);
    size_t siz = strlen(buf);
    buf[siz - 1] = '\0';
    return buf;
}

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

vector<string> work(const string& str) {
    istringstream is(str);
    vector<string> res;

    string s;
    while (is >> s) {
        res.push_back(s);
    }

    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    unordered_map<string, int> ids;
    vector<string> names(n);
    int id = 0;

    auto get = [&](const string& s) {
        if (!ids.count(s)) {
            names[id] = s;
            ids[s] = id++;
        }
        return ids[s];
    };

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int _ = 0; _ < n; _++) {
        auto s = lxt();
        auto ops = work(s);
        string fn = ops[0]; fn.pop_back();
        int fa = get(fn);
        int m = ops.size();
        for (int i = 1; i < m; i++) {
            int dep = get(ops[i]);
            adj[dep].push_back(fa);
        }
    }

    auto src = nxt();

    vector<bool> seen(n);
    queue<int> q;

    auto append = [&](int v) {
        if (!seen[v]) {
            q.push(v);
            seen[v] = true;
        }
    };

    append(get(src));

    vector<int> good;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        good.push_back(cur);

        for (int nei : adj[cur]) {
            append(nei);
            deg[nei]++;
        }
    }

    for (int cur : good) {
        if (deg[cur] == 0) {
            q.push(cur);
        }
    }

    // topo sort
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        printf("%s\n", names[cur].c_str());

        for (int nei : adj[cur]) {
            if (--deg[nei] == 0) {
                q.push(nei);
            }
        }
    }
}