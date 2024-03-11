/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 03:52:20
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
    int n;
    scanf("%d", &n);

    auto check = [&](int x) {
        int sum = 0, prod = 1;
        while (x) {
            int d = x % 10;
            if (d == 0) return false;
            sum += d;
            prod *= d;
            x /= 10;
        }
        return sum >= prod;
    };

    puts("1");
    // int m = 1;
    // for (int i = 0; i * i <= n; i++) {

    // }
}

// ~ Just Jie