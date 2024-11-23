/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2024 12:03:41
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 4, inf = int(1e9) + 5;
int a[N];
int o[N];

struct Frac {
    i64 a, b;
    Frac() {}
    Frac(i64 _a, i64 _b): a(_a), b(_b) {}

    void div(const Frac& x) {
        a *= x.b;
        b *= x.a;
    }
    void mul(const Frac& x) {
        a *= x.a;
        b *= x.b;
    }
    void norm(int l) {
        int g = l / b;
        a *= g;
        b *= g;
    }
    void add(Frac x) {
        int l = lcm(b, x.b);
        norm(l);
        x.norm(l);
        a += x.a;
    }
    void sub(Frac x) {
        int l = lcm(b, x.b);
        norm(l);
        x.norm(l);
        a -= x.a;
    }
    bool good() {
        if (a < 0) {
            return false;
        }
        return (a % b == 0 && a / b == 24);
    }
};

struct Node {
    int e, op;
    Node* L;
    Node* R;
};

void work() {
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        o[i] = a[i];
    }

    sort(o, o + N);

    auto inv = [&]() {
        int used[N] {};
        int pos[N];
        for (int i = 0; i < N; i++) {
            pos[i] = a[i];
        }
        int swaps = 0;
        for (int i = 0; i < N; i++) {
            int j = i;
            while (pos[j] != o[i]) {
                j++;
            }
            for (int k = j - 1; k >= i; k--) {
                swap(pos[k], pos[k + 1]);
                swaps++;
            }
        }
        return swaps;
    };

    auto op = [&](Frac f, Frac x, int which) -> Frac {
        if (which == 0) {
            f.div(x);
            return f;
        } else if (which == 1) {
            f.mul(x);
            return f;
        } else if (which == 2) {
            f.add(x);
            return f;
        } else {
            f.sub(x);
            return f;
        }
        assert(false);
    };

    auto solve = [&]() {
        Node tr[N];
        for (int i = 0; i < N; i++) {
            tr[i].e = o[i];
            tr[i].op = -1;
            tr[i].L = tr[i].R = nullptr;
        }

        int res = inf;
        int cnt = 0;
        auto rec = [&](auto&& self, int i) {
            if (i == N) {
                if (tr[0].e == 24) {
                    res = min(res, cnt);
                }
            } else {
                for (int j = 1; j < N; j++) {
                    
                }
            }
        };

        return res;
    };

    int ans = inf;
    do {
        int res = inv() + solve();
        ans = min(ans, res);
    } while (next_permutation(o, o + N));

    if (ans == inf) {
        cout << "impossible\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie