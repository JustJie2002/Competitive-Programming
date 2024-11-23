
template <typename T>
struct PSum {
    vector<T> pre;
    vector<T> init;
    int n;

    PSum(int _n) : n(_n), pre(n + 1), init(n) {}
    PSum(const vector<T> &_init) : init(_init) {
        n = init.size();
        pre.resize(n + 1);
        work();
    }

    void work() {
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + init[i];
        }
    }

    // set, get
    T& operator[](int i) {
        assert(0 <= i && i < n);
        return init[i];
    }

    // sum between [L, R] inclusive both sides
    T get(int L, int R) const {
        assert(0 <= L && L < n);
        assert(0 <= R && R < n);
        assert(L <= R);
        return pre[R + 1] - pre[L];
    }
};
