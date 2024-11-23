
template <typename T>
struct PSum2D {
    vector<vector<T>> pre;
    vector<vector<T>> init;
    int n, m;

    PSum2D(int _n, int _m) : n(_n), m(_m), pre(n + 1, vector<T>(m + 1)), init(n, vector<T>(m)) {}
    PSum2D(const vector<vector<T>> &_init) : init(_init) {
        n = init.size();
        m = init[0].size();
        pre.resize(n + 1, vector<T>(m + 1));
        work();
    }

    void work() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + init[i][j];
            }
        }
    }

    T& operator() (int r, int c) {
        assert(0 <= r && r < n);
        assert(0 <= c && c < m);
        return init[r][c];
    }

    T get(int r1, int c1, int r2, int c2) const {
        assert(0 <= r1 && r1 < n);
        assert(0 <= r2 && r2 < n);
        assert(0 <= c1 && c1 < m);
        assert(0 <= c2 && c2 < m);
        assert(r1 <= r2);
        assert(c1 <= c2);
        return pre[r2 + 1][c2 + 1] - pre[r2 + 1][c1] - pre[r1][c2 + 1] + pre[c1][c2];
    }
};
