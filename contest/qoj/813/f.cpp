/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 22:57:09
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

// Credit: Jiangly
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 998'244'353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 1'000'000'007; // 998'244'353;
using Z = MInt<P>;


constexpr int A = 26, TOT = 1 << A;
const string VOWELS = "aeiou";

Z dp1[5][52];
Z dp[5];

// dp[pos][mask]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    const auto good = [&](char c) {
        c = tolower(c);
        return VOWELS.find(c) != string::npos;
    };
    const auto ord = [&](char c) {
        int o = 0;
        if (isupper(c)) {
            o += 26;
            c = tolower(c);
        }
        o += (c - 'a');
        return o;
    };

    for (auto c : s) {
        if (good(c)) {
            // suppose it's 5th
            Z res = dp[3] - dp1[0][ord(c)] - dp1[2][ord(c)];
            dp[4] += res;
            // suppose it's 3rd
            res = dp[1] - dp1[0][ord(c)];
            dp[2] += res;
            dp1[2][ord(c)] += res;
            // suppose it's 1st
            res = 1;
            dp[0] += res;
            dp1[0][ord(c)] += res;
        } else {
            // suppose it's 4th
            Z res = dp[2] - dp1[2][ord(c)];
            dp[3] += res;
            dp1[3][ord(c)] += res;
            // suppose it's 2nd
            res = dp[0];
            dp[1] += res;
            dp1[1][ord(c)] += res;
        }
        for (int j = 0; j < 5; j++) {
            cerr << dp[j] << " \n"[j == 5 - 1];
        }
    }

    cout << dp[4] << "\n";
}

// ~ Just Jie