/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 20:48:34
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

double PI = acos(-1.0), G = 9.81;

void workout(int tc) {
    double v0, theta, x, lo, hi;
    scanf("%lf%lf%lf%lf%lf", &v0, &theta, &x, &lo, &hi);

    double rad = 1.0 * theta * PI / 180;

    double t = x / (v0 * cos(rad));
    double y = v0 * t * sin(rad) - (1.0 / 2) * G * t * t;
    puts(y - lo >= 1.0 && hi - y >= 1.0  ? "Safe" : "Not Safe");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}