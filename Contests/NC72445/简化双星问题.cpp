/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 22:24:54
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

int main() {
    double m1, m2, L, m;
    scanf("%lf%lf%lf%lf", &m1, &m2, &L, &m);

    double a = m2 - m1;
    double b = 2 * m1 * L;
    double c = -m1 * L * L;

    if (m1 == m2) {
        printf("%0.3lf\n", L / 2);
        return 0;
    }

    double top1 = -b + sqrtl(b * b - 4. * a * c);
    double top2 = -b - sqrtl(b * b - 4. * a * c);
    double bot = 2 * a;

    double ans1 = top1 / bot;
    double ans2 = top2 / bot;
    if (ans1 > 0) {
        printf("%0.3lf\n", ans1);
    } else {
        printf("%0.3lf\n", ans2);
    }
}