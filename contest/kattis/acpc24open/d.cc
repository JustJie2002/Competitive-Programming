/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 14:36:06
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const double PI = acos(-1);

void work() {
    int n;
    double R;
    cin >> R >> n;
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        double r;
        cin >> r;
        if (0 < r && (r - PI * R) <= 1e-6) {
            double area = 2. * PI;
            area *= R * R;
            area *= (1. - cos(1. * r / R));
            cout << area << "\n";
        } else {
            double area = 4. * PI * R * R;
            cout << area << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie