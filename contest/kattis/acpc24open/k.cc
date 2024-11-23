/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 16:12:33
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

using Factor = pair<int, int>;

constexpr int MAX_SIEVE = 3e7 + 5;
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

i64 ask(i64 x) {
    cout << "q " << x << "\n";
    cout << flush;
    i64 rem;
    cin >> rem;
    return rem;
}

void ans(i64 x) {
    cout << "a " << x << "\n";
    cout << flush;
}

constexpr int N = int(1e5);

void work() {
    i64 rem = ask(N);
    i64 kp = 1LL * N * N - rem;
    set<i64> ps;
    for (int pr : primes.primes) {
        if (pr > kp) {
            break;
        }
        if (kp % pr == 0) {
            int cnt = 0;
            while (kp % pr == 0) {
                cnt++;
                kp /= pr;
            }
            ps.insert(pr);
        }
    }
    if (kp > 1) {
        ps.insert(kp);
    }

    vector<i64> p(ps.begin(), ps.end());

    int sz = p.size();
    assert(sz <= 8);
    int lo = 0, hi = sz - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        i64 prod = 1;
        for (int i = lo; i <= mid - ((hi - lo + 1) & 1); i++) {
            prod *= p[i];
        }
        if (prod > N) {
            while (true) {}
        }
        if (ask(prod) == 0) {
            hi = mid - ((hi - lo + 1) & 1);
        } else {
            lo = mid + (((hi - lo + 1) & 1) ^ 1);
        }
    }
    ans(p[hi]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie