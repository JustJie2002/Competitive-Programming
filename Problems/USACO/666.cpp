/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.22.2024 00:44:37
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

void usaco(const string& fname) {
    string input = fname + ".in";
    string output = fname + ".out";
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
}

int main() {
    usaco("haybales");
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    sort(s.begin(), s.end());

    for (; Q--; ) {
        int a, b;
        scanf("%d%d", &a, &b);
        auto L = lower_bound(s.begin(), s.end(), a);
        auto R = upper_bound(s.begin(), s.end(), b);
        printf("%d\n", int(R - L));
    }
}

// ~ Just Jie