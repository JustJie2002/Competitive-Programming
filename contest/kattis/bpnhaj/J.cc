/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:26:55
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

bool div(int a, int b, int c) {
    if (a % b) {
        return false;
    }
    return a / b == c;
}

bool sub(int a, int b, int c) {
    return a - b == c;
}

bool add(int a, int b, int c) {
    return a + b == c;
}

bool mul(int a, int b, int c) {
    return a * b == c;
}

void work(int tc) {
    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < 2; j++) {
        swap(a[0], a[1]);
        if (div(a[0], a[1], a[2]) || sub(a[0], a[1], a[2]) || mul(a[0], a[1], a[2]) || add(a[0], a[1], a[2])) {
            cout << "Possible\n";
            return;
        }
    }
    cout << "Impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ JustJie