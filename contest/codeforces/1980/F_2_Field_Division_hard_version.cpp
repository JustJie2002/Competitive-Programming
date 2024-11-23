/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 11:17:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Pos = array<int, 2>;

constexpr int inf = -1e9 + 5;

// Credit: Jiangly
template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
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
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
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
    int x; 
    void apply(const Tag &t) {
        x = max(x, t.x);
    }
};
struct Info {
    int v = 0, r = 0, tot = 0;
    void apply(const Tag &t) {
        r = t.x;
        tot = v * r;
    }
};
 
Info operator+(const Info &a, const Info &b) {
    Info c = {0, 0, a.tot + b.tot};
    if (a.v != 0) {
        
    }
}

void work(int tc) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Pos> a(k);
    map<int, vector<int>, greater<int>> pos;
    map<int, vector<int>> pos2;
    map<int, int> compress;
    for (int i = 0; auto &[r, c] : a) {
        cin >> r >> c;
        if (!compress.contains(c)) {
            compress[c];
        }
        pos[r].push_back(i);
        pos2[r].push_back(i);
        i++;
    }
    compress[1];
    compress[m];

    map<int, int> to_val;
    for (auto &[k, v] : compress) {
        compress[v] = id;
        to_val[id] = v;
        id++;
    }

    i64 l_most = m + 1;
    vector<i64> ans(k, 1);
    int p = n;
    i64 res = 0;
    
    for (auto &[r, v] : pos) {
        sort(v.begin(), v.end(),
            [&](int i, int j) {
                return a[i][1] < a[j][1];
            });
        res += (l_most - 1) * (p - r);
        for (int i : v) {
            if (l_most <= a[i][1]) {
                ans[i] = 0;
            }
            l_most = min<i64>(l_most, a[i][1]);
        }
        p = r;
    }
    res += (l_most - 1) * p;
    cout << res << "\n";

    vector<Info> init(id);
    for (int i = 0; i < id; i++) {
        init = {to_val[i], 0, 0};
    }
    LazySegmentTree<Info, Tag> seg(init);
    for (auto &[r, v] : pos2) {
        sort(v.begin(), v.end(),
            [&](int i, int j) {
                return a[i][1] > a[j][1];
            });
        res += (l_most - 1) * (p - r);
        for (int i : v) {
            if (l_most <= a[i][1]) {
                ans[i] = 0;
            } else {
                ans[i] = 1LL * r * a[i][1] - seg.range_query(compress[a[i][1]], compress[m] + 1);
            }
            l_most = min<i64>(l_most, a[i][1]);
        }
        p = r;
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

// ~ Just Jie