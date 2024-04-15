
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
