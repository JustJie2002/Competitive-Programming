
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = int(1e9) + 7;

template<typename T, bool RAND = true, bool LEFT_HASH = true>
struct HashOnce {
    static int global_base1, global_base2;
    static vector<i64> powers1, inv_powers1, powers2, inv_powers2;
    vector<i64> pre;

    HashOnce(const T &s, int b = 131) {
        int n = s.size();
        int &chosen_base = LEFT_HASH ? global_base1 : global_base2;
        vector<i64> &powers = LEFT_HASH ? powers1 : powers2;
        vector<i64> &inv_powers = LEFT_HASH ? inv_powers1 : inv_powers2;
        if (!chosen_base) {
            chosen_base = RAND ? uniform_int_distribution<int>(200, MOD - 1)(rng) : b;
            i64 cur = chosen_base, inv = 1;
            for (int exp = MOD - 2; exp; exp >>= 1) {
                if (exp & 1) {
                    inv = (inv * cur) % MOD;
                }
                cur = (cur * cur) % MOD;
            }
            powers.push_back(chosen_base);
            inv_powers.push_back(inv);
        }
        while (powers.size() < n) {
            powers.push_back(powers.back() * chosen_base % MOD);
            inv_powers.push_back(inv_powers.back() * inv_powers[1] % MOD);
        }
        pre.resize(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = (pre[i] + s[i] * (LEFT_HASH ? powers1 : powers2)[i]) % MOD;
        }
    }
    HashOnce() {}

    i64 get(int L, int R) {
        return (pre[R + 1] - pre[L] + MOD) * (LEFT_HASH ? inv_powers1 : inv_powers2)[L] % MOD;
    }
};

template<typename T, bool R, bool LEFT_HASH> int HashOnce<T, R, LEFT_HASH>::global_base1 = 0;
template<typename T, bool R, bool LEFT_HASH> int HashOnce<T, R, LEFT_HASH>::global_base2 = 0;
template<typename T, bool R, bool LEFT_HASH> vector<i64> HashOnce<T, R, LEFT_HASH>::powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> HashOnce<T, R, LEFT_HASH>::powers2 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> HashOnce<T, R, LEFT_HASH>::inv_powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> HashOnce<T, R, LEFT_HASH>::inv_powers2 = {1};

template<typename T, bool RAND = true>
struct HashTwice {
    HashOnce<T, RAND, true> hash1;
    HashOnce<T, RAND, false> hash2;

    HashTwice(const T &s, int base1 = 131, int base2 = 173) : 
        hash1(HashOnce<T, RAND, true>(s, base1)),
        hash2(HashOnce<T, RAND, false>(s, base2)) {}
    HashTwice() {}

    // Get hash [L, R] inclusive both sides
    i64 get(int L, int R) {
        return (hash1.get(L, R) << 32) | hash2.get(L, R);
    }
};

template <typename T>
using Hash = HashTwice<T, true>;
