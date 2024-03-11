
template<class T> constexpr T power(T a, i64 b) {
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
template<int P> struct MInt {
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
int MInt<0>::Mod = 998244353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 0;
using Z = MInt<P>;

// Credit: https://github.com/Joshc88/CPTemplates/blob/main/String/hashing.h
struct StringHash {
    int base, sz, mod;
    Z inv;
    vector<Z> pow = {1}, inverse = {1}, pre = {0};

    StringHash(string s, int m = 1000000007, int b = 131) {
        sz = s.size();
        base = b;
        inv.setMod(m);
        pow[0].setMod(m);
        inverse.setMod(m);
        pre.setMod(m);

        inv = 1;
        Z cur = base;
        int exp = m - 2;
        for (int exp = m - 2; exp; exp >>= 1) {
            if (exp & 1) {
                inv = inv * cur;
            }
        }

        for (int i = 0; i < sz; i++) {
            pow.push_back(pow.back() * base);
            inverse.push_back(inverse.back() * inv);
            pre.push_back(pre.back() + s[i] * pow[i]);
        }
    }

    StringHash() {}
    
    int get(int l, int r) {
        Z sub_hash = (pre[r+1] - pre[l]) * inverse[l];
        return sub_hash.val();
    }
};

struct SafeStringHash {
    StringHash hash1, hash2;
    
    SafeStringHash(string S, int base1 = 131, int base2 = 149, int mod1 = 1000000007, int mod2 = 998244353) {
        hash1 = StringHash(S, mod1, base1);
        hash2 = StringHash(S, mod2, base2);
    }
    
    pair<int, int> get(int l, int r) {
        return make_pair(hash1.get(l, r), hash2.get(l, r));
    }
};
