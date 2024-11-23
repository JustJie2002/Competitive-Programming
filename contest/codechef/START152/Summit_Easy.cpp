/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.19.2024 00:21:57
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

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
    int curL, curR;
    int patL, patR;
    int size;
    i64 ans;
    Info(int x): curL(x), curR(x), ans(1LL), patL(1), patR(1), size(1) {}
    Info() {}
};

void debug(const Info& a) {
    dbg(a.curL, a.curR, a.patL, a.patR, a.size, a.ans);
}
 
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.curL = a.curL;
    c.curR = b.curR;
    c.ans = a.ans + b.ans;
    c.size = a.size + b.size;
    c.patL = a.patL;
    c.patR = b.patR;
    if (a.curR < b.curL) {
        if (a.patR == a.size) {
            c.patL = a.size + b.patL;
        }
        if (b.patL == b.size) {
            c.patR = b.size + a.patR;
        }
        c.ans += 1LL * b.patL * a.patR;
    }
    return c;
}

void work(int tc) {
    int n;
    cin >> n;

    vector<Info> init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        init[i] = Info(a[i]);
    }

    SegmentTree<Info> seg(init);

    i64 ans = seg.prod().ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = a[i], y = a[j];
            seg[i] = Info(y);
            seg[j] = Info(x);
            ans = max(ans, seg.prod().ans);
            seg[i] = Info(x);
            seg[j] = Info(y);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ JustJie