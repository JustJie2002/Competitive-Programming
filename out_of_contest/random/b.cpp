/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 18:09:57
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

using Factor = pair<int, int>;

constexpr int MAX_SIEVE = 1e6 + 5;
struct PrimeTable {
    vector<int> minp, primes;

    PrimeTable(int n) {
        sieve(n);
    }

    void sieve(int n) {
        minp.assign(n + 1, 0);
        primes.clear();
        
        for (int i = 2; i <= n; i++) {
            if (minp[i] == 0) {
                minp[i] = i;
                primes.push_back(i);
            }
            
            for (auto p : primes) {
                if (i * p > n) {
                    break;
                }
                minp[i * p] = p;
                if (p == minp[i]) {
                    break;
                }
            }
        }
    }

    int sf(int x) {
        return minp[x];
    }
    
    bool is_prime(int x) {
        return sf(x) == x;
    }

    vector<Factor> prime_factorize(int x) {
        vector<Factor> factors;
        int cur_prime = 0, freq = 0;
        while (x != 1) {
            int v = sf(x);
            if (cur_prime == v) {
                freq++;
            } else {
                if (freq) {
                    factors.emplace_back(cur_prime, freq);
                }
                cur_prime = v;
                freq = 1;
            }
            x /= v;
        }
        if (freq) {
            factors.emplace_back(cur_prime, freq);
        }
        return factors;
    }

    vector<int> get_factors(int x) {
        vector<int> a, b;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                a.push_back(i);
                if (i * i != x) {
                    b.push_back(x / i);
                }
            }
        }
        reverse(b.begin(), b.end());
        for (int x : b) {
            a.push_back(x);
        }
        return a;
    }
} primes(MAX_SIEVE);

constexpr int N = 2e5 + 5;
int a[N];
i64 tr[4 * N];
int n;

void make_tree(int p, int l, int r) {
    if (l == r) {
        tr[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    make_tree(2 * p, l, m);
    make_tree(2 * p + 1, m + 1, r);
    tr[p] = tr[2 * p] + tr[2 * p + 1];
}

void range_modify(int p, int l, int r, int x, int y) {
    if (l == r) {
        int d = primes.sf(tr[p]);
        tr[p] /= d;
        return;
    }
    if (l == x && r == y && tr[p] == (r - l + 1)) {
        return;
    }
    int m = (l + r) / 2;
    if (y <= m) {
        range_modify(2 * p, l, m, x, y);
    } else if (x > m) {
        range_modify(2 * p, m + 1, r, x, y);
    } else {
        range_modify(2 * p, l, m, x, m);
        range_modify(2 * p + 1, m + 1, r, m + 1, y);
    }
    tr[p] = tr[2 * p] + tr[2 * p + 1];
}

void range_modify(int x, int y) {
    range_modify(1, 0, n - 1, x, y);
}

void modify(int p, int l, int r, int x, int v) {
    if (l == r) {
        tr[p] = v;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        range_modify(2 * p, l, m, x, v);
    } else {
        range_modify(2 * p, m + 1, r, x, v);
    }
    tr[p] = tr[2 * p] + tr[2 * p + 1];
}

void modify(int x, int v) {
    modify(1, 0, n - 1, x, v);
}

i64 range_query(int p, int l, int r, int x, int y) {
    if (l == x && r == y) {
        return tr[p];
    }
    int m = (l + r) / 2;
    i64 res = 0;
    if (y <= m) {
        res += range_query(2 * p, l, m, x, y);
    } else if (x > m) {
        res += range_query(2 * p, m + 1, r, x, y);
    } else {
        res += range_query(2 * p, l, m, x, m);
        res += range_query(2 * p + 1, m + 1, r, m + 1, y);
    }
    return res;
}

i64 range_query(int x, int y) {
    return range_query(1, 0, n - 1, x, y);
}

int main() {
    int Q;
    scanf("%d%d", &n, &Q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    make_tree(1, 0, n - 1);

    while (Q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            range_modify(l, r);
        } else if (op == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            i64 ans = range_query(l, r);
            printf("%lld\n", ans);
        } else if (op == 3) {
            int x, v;
            scanf("%d%d", &x, &v);
            x--;
            modify(x, v);
        } else assert(false);
    }
}

// ~ Just Jie