/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 13:37:23
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Info = pair<int, int>;

// Credit: Jiangly
template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream &operator<<(std::ostream &os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) {
            return os << x.num / g;
        } else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};

int main() {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);

    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);

    auto get = [&](int sx, int sy, int ex, int ey) -> Frac<int> {
        int rise = ey - sy;
        int run = ex - sx;
        int g = gcd(abs(rise), abs(run));
        return Frac<int>(rise, run);
    };

    auto cur_slope = get(sx, sy, ex, ey);

    if (sx == ex) {
        if (ey > sy) {
            puts("top");
        } else {
            puts("bottom");
        }
        return 0;
    }

    // we have bot-left, top-right
    auto bl = get(sx, sy, x1, y1);
    auto br = get(sx, sy, x2, y1);
    auto tl = get(sx, sy, x1, y2);
    auto tr = get(sx, sy, x2, y2);

    if (ex < sx && ey < sy) {
        if (cur_slope == bl) {
            puts("bottom-left");
        } else if (cur_slope < bl) {
            puts("left");
        } else {
            puts("bottom");
        }
    } else if (ex > sx && ey < sy) {
        if (cur_slope == br && ex > sx && ey < sy) {
            puts("bottom-right");
        } else if (cur_slope < br) {
            puts("bottom");
        } else {
            puts("right");
        }
    } else if (ex < sx && ey > sy) {
        if (cur_slope == tl) {
            puts("top-left");
        } else if (cur_slope > tl) {
            puts("left");
        } else {
            puts("top");
        }
    } else {
        if (cur_slope == tr) {
            puts("top-right");
        } else if (cur_slope > tr) {
            puts("top");
        } else {
            puts("right");
        }
    }
}

// ~ Just Jie