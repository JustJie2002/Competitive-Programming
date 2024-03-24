/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 15:41:50
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    static string nxt() {
        scanf("%s", buf);
        return buf;
    }
    static char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    static string lxt() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;

// Credit: JoshC
template<typename T, bool R = true, bool LEFT_HASH = true>
struct hashes {
    mt19937 rng;
    const static int MOD = 1e9 + 7;
    static int global_base1, global_base2;
    static vector<long long> powers1, inv_powers1, powers2, inv_powers2;
    vector<long long> psa;

    hashes(T& s, int b = 131) : rng(chrono::steady_clock::now().time_since_epoch().count()), psa{0} {
        int& chosen_base = LEFT_HASH ? global_base1 : global_base2;
        vector<long long> &powers = LEFT_HASH ? powers1 : powers2,
            &inv_powers = LEFT_HASH ? inv_powers1 : inv_powers2;
        if (!chosen_base) {
            chosen_base = R ? uniform_int_distribution<int>(200, MOD - 1)(rng) : b;
            long long cur = chosen_base, inv = 1;
            for (int exp = MOD - 2; exp; exp >>= 1) {
                if (exp & 1) inv = inv * cur % MOD;
                cur = cur * cur % MOD;
            }
            powers.push_back(chosen_base);
            inv_powers.push_back(inv);
        }
        while (powers.size() < s.size()) {
            powers.push_back(powers.back() * chosen_base % MOD);
            inv_powers.push_back(inv_powers.back() * inv_powers[1] % MOD);
        }
        for (int i = 0; i < s.size(); i++) psa.push_back((psa.back() + s[i] * (LEFT_HASH ? powers1 : powers2)[i]) % MOD);
    }

    hashes() {}

    long long get(int l, int r) {
        return (psa[r + 1] - psa[l] + MOD) * (LEFT_HASH ? inv_powers1 : inv_powers2)[l] % MOD;
    }
};

template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base1 = 0;
template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base2 = 0;
template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::powers2 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::inv_powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::inv_powers2 = {1};

template<typename T, bool R = true> 
struct double_hash {
    hashes<T, R, true> hash1;
    hashes<T, R, false> hash2;

    double_hash(T& s, int base1 = 131, int base2 = 173) : hash1(hashes<T, R, true>(s, base1)),
                                                                             hash2(hashes<T, R, false>(s, base2)) {}
    double_hash() {}

    long long get(int l, int r) {
        return (hash1.get(l, r) << 32) | hash2.get(l, r);
    }
};

using i64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    auto s = fs.nxt();
    auto t = fs.nxt();

    double_hash<string> shash(s);
    double_hash<string> thash(t);

    vector dp(n + 1, vector(n + 1, vector<bool>(m + 1)))
    dp[0][0][0] = true;
    for (int i = 1; i < n; i++) {
        for (int )
    }
}

// ~ Just Jie