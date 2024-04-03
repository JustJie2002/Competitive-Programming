
using Pair = pair<int, int>;

struct UndoDSU {
    vector<int> par;
    stack<Pair, vector<Pair>> ops;

    UndoDSU() {}
    UndoDSU(int n): par(n, -1) {}

    int find(int x) {
        return par[x] < 0 ? x : find(par[x]);
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (par[x] > par[y]) {
            swap(x, y);
        }
        ops.emplace(x, par[x]);
        ops.emplace(y, par[y]);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[find(x)];
    }

    void undo() {
        assert(!ops.empty());
        for (int _ = 0; _ < 2; _++) {
            auto [cur, fa] = ops.top();
            ops.pop();
            par[cur] = fa;
        }
    }
};
