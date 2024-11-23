/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.14.2024 23:33:02
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Segment = array<int, 2>;

struct DSU {
    vector<int> par, siz;
    vector<Segment> seg;
    int components;

    DSU() {}
    DSU(int n): components(n), seg(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            seg[i] = {i, i};
        }
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
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        seg[x][0] = min(seg[x][0], seg[y][0]);
        seg[x][1] = max(seg[x][1], seg[y][1]);
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
    Segment get(int x) {
        return seg[find(x)];
    }
};

int n, q;

bool read() {
    cin >> n >> q;
    return max(n, q) > 0;
}

// Solution for non-overlapping report
// O(Q + alpha(N))
void work() {
    DSU uf(n);
    vector<bool> dead(n);

    while (q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;

        if (L - 1 >= 0 && dead[L - 1]) {
            uf.merge(L - 1, L);
        }
        for (int i = L; i < R; i++) {
            dead[i] = true;
            uf.merge(i, i + 1);
        }
        dead[R] = true;
        if (R + 1 < n && dead[R + 1]) {
            uf.merge(R, R + 1);
        }

        auto [a, b] = uf.get(L);
        a--;
        b++;
        if (a >= 0) {
            cout << a + 1 << " ";
        } else {
            cout << "* ";
        }
        if (b < n) {
            cout << b + 1 << "\n";
        } else {
            cout << "*\n";
        }
    }
    cout << "-\n";
}

// Solution for overlapping report
// void work() {
//     set<Segment> segs;
//     segs.insert({1, n});

//     auto remove = [&](int L, int R) -> void {
//         Segment cur {L + 1, 0};
//         auto it = segs.lower_bound(cur);
//         if (it != segs.begin()) {
//             it--;
//         }
//         while (it != segs.end()) {
//             auto nex = next(it);

//             auto [a, b] = *it;
//             if (a > R) {
//                 break;
//             }
//             if (b < L) {
//                 it = nex;
//                 goto end;
//             }
//             segs.erase(it);
//             if (a < L) {
//                 segs.insert({a, L - 1});
//             }
//             if (b > R) {
//                 segs.insert({R + 1, b});
//             }

//             end:;
//             it = nex;
//         }
//         dbg(segs);
//     };
//     auto answer = [&](int L, int R) -> void {
//         auto it = segs.lower_bound({L, 0});
//         if (it == segs.begin()) {
//             cout << "* ";
//         } else {
//             it--;
//             cout << (*it)[1] << " ";
//         }
//         auto it2 = segs.upper_bound({R, 0});
//         if (it == segs.end()) {
//             cout << "*\n";
//         } else {
//             cout << (*it2)[0] << "\n";
//         }
//     };

//     while (q--) {
//         int a, b;
//         cin >> a >> b;
//         remove(a, b);
//         answer(a, b);
//     }
//     cout << "-\n";
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (read()) {
        work();
    }
}

// ~ Just Jie