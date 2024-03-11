/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 18:27:18
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

constexpr int INF = 1e9 + 5;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    map<int, int> freq;
    int mi = INF;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
        mi = min(mi, a[i]);
    }

    if (freq[mi] == 1) {
        puts("YES");
        return;
    }

    if (mi == 1) {
        puts("NO");
        return;
    }

    for (int x : a) {
        if (x % mi) {
            puts("YES");
            return;
        }
    }

    puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie