/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 00:55:18
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

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
using Base = MInt<0>;
using Info = vector<Z>;

constexpr int K = 10;
int c[K];
int B, k;

Info pow(const Info& a, i64 n) {
    Info res(B);
    Base pw10 = power(Base(10), n);
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
            int nex = (pw10 * i + j).val();
            res[nex] += a[i] * a[j];
        }
    }
    return res;
}

Info add(const Info& dp) {
    Info ndp(B);
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < k; j++) {
            int nex = (Base(i) * 10 + c[j]).val();
            ndp[nex] += dp[i];
        }
    }
    return ndp;
}

Info power(i64 n) {
    Info res(B);
    if (n == 0) {
        res[0] = 1;
        return res;
    }
    res = pow(power(n / 2), n / 2);
    if (n & 1) {
        res = add(res);
    }
    return res;
}

// O(B^2 log N)
int main() {
    i64 n;
    scanf("%lld%d%d", &n, &B, &k);
    Base::setMod(B);

    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        
    }

    auto ans = power(n);
    printf("%d\n", ans[0].val());
}

// ~ Just Jie