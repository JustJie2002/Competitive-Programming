/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.11.2024 01:49:56
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
};

int gcd(int a, int b) {
    if (b) {
        return gcd(b, a % b);
    }
    return a;
}

struct Frac {
    int num, den;
    Frac() {}
    Frac(int num, int den): num(num), den(den) { init(); }

    void init() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    friend bool operator < (const Frac& rhs) {
        return num * rhs.den < den * rhs.num;
    }
};

Frac get(const Point& a, const Point& b) {
    int dy = b.y - a.y;
    int dx = b.x - a.x;
    if (dy == 0 || dx == 0) {
        return Frac(inf, inf);
    }
    return Frac(dy, dx);
}

Frac perp(Frac frac) {
    swap(frac.num, frac.den);
    frac.num *= -1;
    return frac;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& p : points) {
        cin >> p.x >> p.y;
    }

    for (int i = 0; i < n; i++) {
        map<Frac, int> occs;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            auto frac = get(points[i], points[j]);
            if (frac.num == inf && frac.den == inf) {
                continue;
            }
            occs[Frac]++;
        }
    }
}

// ~ JustJie