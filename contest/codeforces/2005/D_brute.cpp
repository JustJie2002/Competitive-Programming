/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 03:57:37
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
    int x;
};
 
Info operator+(const Info& a, const Info& b) {
    return {gcd(a.x, b.x)};
}
 
void work(int tc) {
    int n;
    cin >> n;
 
    vector<int> a(n), b(n);
    cin >> a >> b;
 
    vector<int> pre_a(n, 1), suf_a(n, 1);
    vector<int> pre_b(n, 1), suf_b(n, 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_a[i] = a[i];
        } else {
            pre_a[i] = gcd(pre_a[i - 1], a[i]);
        }
        if (pre_a[i] == 1) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_b[i] = b[i];
        } else {
            pre_b[i] = gcd(pre_b[i - 1], b[i]);
        }
        if (pre_b[i] == 1) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf_a[i] = a[i];
        } else {
            suf_a[i] = gcd(suf_a[i + 1], a[i]);
        }
        if (suf_a[i] == 1) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf_b[i] = b[i];
        } else {
            suf_b[i] = gcd(suf_b[i + 1], b[i]);
        }
        if (suf_b[i] == 1) {
            break;
        }
    }
 
    const auto my_swap = [&](int L, int R, int b_g, int a_g) -> int {
        if (L != 0) {
            a_g = gcd(a_g, pre_a[L - 1]);
            b_g = gcd(b_g, pre_b[L - 1]);
        }
        if (R != n - 1) {
            a_g = gcd(a_g, suf_a[R + 1]);
            b_g = gcd(b_g, suf_b[R + 1]);
        }
        return a_g + b_g;
    };
 
    int max_g = 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a_g = a[i];
        int b_g = b[i];
        for (int j = i; j < n; j++) {
            a_g = gcd(a_g, a[j]);
            b_g = gcd(b_g, b[j]);
            int new_g = my_swap(i, j, a_g, b_g);
            if (new_g > max_g) {
                max_g = new_g;
                count = 1;
            } else if (new_g == max_g) {
                count++;
            }
            if (a_g == 1 && b_g == 1) {
                break;
            }
        }
    }
 
    if (max_g == 2) {
        cout << 2 << " " << 1LL * n * (n + 1) / 2 << "\n";
    } else {
        cout << max_g << " " << count << "\n";
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