/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 13:26:25
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

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename K, typename V, typename Hash = custom_hash>
using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;

using Factor = pair<int, int>;

constexpr int MAX_SIEVE = 3e4 + 5;
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

void work(int tc) {
    int a, b;
    scanf("%d%d", &a, &b);

    auto get_space = [&](int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());

        HashSet<int> pf;
        do {
            int v = stoi(s);
            bool is_prime = true;
            for (int p : primes.primes) {
                if (1LL * p * p > v) {
                    break;
                }
                if (v % p == 0) {
                    pf.insert(p);
                    while (v % p == 0) {
                        v /= p;
                    }
                }
            }
            if (v > 1) {
                pf.insert(v);
            }
        } while (next_permutation(s.begin(), s.end()));
        return pf;
    };

    auto sa = get_space(a);
    auto sb = get_space(b);

    int ans = 1;
    for (int x : sa) {
        if (sb.find(x) != sb.end()) {
            ans = max(ans, x);
        }
    }

    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie