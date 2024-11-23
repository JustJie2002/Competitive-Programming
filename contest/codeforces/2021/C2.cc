/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.06.2024 02:14:50
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

namespace reader {
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
};
using namespace reader;

// Credit: Jiangly
template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    vector<int> pos;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
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
        tag.assign(4 << __lg(n), Tag());
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
    Info range_query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return range_query(2 * p, l, m, x, y) + range_query(2 * p + 1, m, r, x, y);
    }
    Info range_query(int l, int r) {
        return range_query(1, 0, n, l, r);
    }
    void range_apply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        range_apply(2 * p, l, m, x, y, v);
        range_apply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void range_apply(int l, int r, const Tag &v) {
        return range_apply(1, 0, n, l, r, v);
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
        push(p);
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
        push(p);
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

struct Tag {
    int x = 0;
    void apply(const Tag &t) {
        x += t.x;
    }
};

struct Info {
    int x = 0;
    void apply(const Tag &t) {
        x += t.x;
    }
};
 
Info operator+(const Info &a, const Info &b) {
    return { a.x + b.x };
}

struct Tag2 {
    int x;
    void apply(const Tag2 &t) {
        x = max(x, t.x);
    }
};

struct Info2 {
    array<int, 2> x {};
    void apply(const Tag2 &t) {
        x[1] = max(x[0], t.x);
    }
};
 
Info2 operator+(const Info2 &a, const Info2 &b) {
    return { a.x[1] + b.x[1], a.x[1] + b.x[1] };
}

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

void work(int tc) {
    int n, m, Q;
    cin >> n >> m >> Q;

    vector<int> a(n);
    cin >> a;
    --a;

    vector<int> b(m);
    cin >> b;
    --b;
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    vector<set<int>> w(n);
    int uni = 0;
    vector<Info> init(m);
    vector<Info2> init2(m);
    for (int i = 0; i < m; i++) {
        int x = b[i];
        if (w[x].empty()) {
            uni++;
        }
        w[x].insert(i);
        init[i] = {uni};
        init2[i] = {pos[x], pos[x]};
    }

    LazySegmentTree<Info, Tag> seg(init);
    LazySegmentTree<Info2, Tag2> seg2(init2);

    auto upd = [&](int i, int x) -> void {
        int cur = b[i];
        if (cur == x) {
            return;
        }
        assert(!w[cur].empty());
        if (*w[cur].begin() == i) {
            int nex = m;
            if (w[cur].size() > 1) {
                nex = *next(w[cur].begin());
            }
            seg.range_apply(i, nex, {-1});
        }
        w[cur].erase(i);

        b[i] = x;
        if (w[x].empty() || *w[x].begin() > i) {
            int nex = m;
            if (!w[x].empty()) {
                nex = *w[x].begin();
            }
            seg.range_apply(i, nex, {1});
        }
        seg2.modify(i, {pos[x], pos[x]});
        seg2.range_apply(i + 1, m, Tag2 {pos[x]});

        w[x].insert(i);
    };

    cout << (seg.range_query(0, m).x != seg2.range_query(0, m).x[0] ? "TIDAK" : "YA") << "\n";
    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--, x--;
        upd(i, x);
        cout << (seg.range_query(0, m).x != seg2.range_query(0, m).x[0] ? "TIDAK" : "YA") << "\n";
    }
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