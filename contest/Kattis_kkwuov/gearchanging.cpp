/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 18:45:41
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

int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);

    vector<int> c(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    vector<double> a;
    a.reserve(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a.push_back(1. * c[i] / b[j]);
        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n * m - 1; i++) {
        // a[i + 1] / a[i] > (100 + p) / 100
        if ((a[i + 1] * 100LL) > (1LL * (100 + p) * a[i])) {
            puts("Time to change gears!");
            return 0;
        }
    }

    puts("Ride on!");
}

// ~ Just Jie