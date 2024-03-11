
// TODO:
template <typename T, class F = function<T(const &T, const &T)>> struct SparseTable2D {
    int n, m;
    vector<vector<vector<vector<T>>>> st;
    F merge;

    SparseTable() {}
    SparseTable(const vector<vector<T>>& aa, const F& f): merge(f) {
        n = aa.size(), m = aa[0].size();
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int lg = 1; lg < max_log; lg++) {
            st[lg].resize(n - (1 << lg) + 1);
            for (int i = 0; i <= n - (1 << lg); i++) {
                st[lg][i] = merge(st[lg - 1][i], st[lg - 1][1 + (1 << (j - 1))]);
            }
        }
    }

    T query(int L, int R) const {
        assert(0 <= L && L <= R && R <= n - 1);
        int lg = 32 - __builtin_clz(R - L + 1) - 1;
        return merge(st[lg][L], st[lg][R - (1 << lg) + 1]);
    }
};
