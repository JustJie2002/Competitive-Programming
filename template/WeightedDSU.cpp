

template <typename T>;
struct DSU {
    vector<int> par, siz;
    vector<T> val;
    int components;

    DSU() {}
    DSU(int n): components(n), val(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y, T w) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        val[x] = val[x] + val[y];
        val[x] = val[x] + w;
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }

    T get(int x) {
        return val[find(x)];
    }
};

struct Info {
    // TODO
};

Info operator+(const Info& a, const Info& b) {
    // TODO
}
