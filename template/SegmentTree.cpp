
// Credit: Jiangly
template <class Info>
class SegmentTree {
private:
    int n;
    vector<Info> info;
    vector<int> pos;
    struct Proxy {
        SegmentTree<Info>& seg;
        int index;
        Proxy(SegmentTree<Info>& seg, int index) : seg(seg), index(index) {}
        Proxy& operator=(const Info& info) {
            seg.modify(index, info);
            return *this;
        }
    };

public:
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        pos.resize(n);
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                pos[l] = p;
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    const Info& operator[](int p) const {
        return range_query(p, p + 1);
    }
    Proxy operator[](int p) {
        return Proxy(*this, p);
    }
    Info range_query(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        if (y <= m) {
            return range_query(2 * p, l, m, x, y);
        } else if (x >= m) {
            return range_query(2 * p + 1, m, r, x, y);
        }
        return range_query(2 * p, l, m, x, m) + range_query(2 * p + 1, m, r, m, y);
    }
    Info range_query(int l, int r) {
        return range_query(1, 0, n, l, r);
    }
    Info get(int i) {
        return info[pos[i]];
    }
    Info prod() {
        return info[1];
    }
    template<class F>
    int find_first(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = find_first(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = find_first(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int find_first(int l, int r, F pred) {
        return find_first(1, 0, n, l, r, pred);
    }
    template<class F>
    int find_last(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = find_last(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = find_last(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int find_last(int l, int r, F pred) {
        return find_last(1, 0, n, l, r, pred);
    }
};

struct Info {
    // TODO
};
 
Info operator+(const Info& a, const Info& b) {
    // TODO
}
