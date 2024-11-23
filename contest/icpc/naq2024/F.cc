/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 20:07:02
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Point = array<double, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point f1, f2;
    double a;
    cin >> f1[0] >> f1[1];
    cin >> f2[0] >> f2[1];
    cin >> a;

    a = a / 2.;
    Point c;
    for (int i = 0; i < 2; i++) {
        c[i] = (f1[i] + f2[i]) / 2.;
    }
    Point delta;
    delta[0] = f1[0] - c[0];
    delta[1] = f1[1] - c[1];
    double d = sqrtl(pow(delta[0], 2) + pow(delta[1], 2));
    double b = sqrtl(pow(a, 2) - pow(d, 2));

    double alpha = -atan2(f2[1] - f1[1], f2[0] - f1[0]);
    double cosa = cos(alpha);
    double sina = sin(alpha);

    double theta = atan2(-b * sina, a * cosa);
    delta[0] = fabs(a * cos(theta) * cosa - b * sin(theta) * sina);
    double xlo = c[0] - delta[0];
    double xhi = c[0] + delta[0];

    theta = atan2(b * cosa, a * sina);
    delta[1] = fabs(a * cos(theta) * sina + b * sin(theta) * cosa);
    double ylo = c[1] - delta[1];
    double yhi = c[1] + delta[1];

    cout << fixed << setprecision(6);
    cout << xlo << " " << ylo << " ";
    cout << xhi << " " << yhi << "\n";
}

// ~ JustJie