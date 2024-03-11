/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 02:52:45
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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
using Pair = pair<int, int>;

void output_vector(const vector<i64>& a) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

void workout(int tc) {
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<i64> a(n);
    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        i64 x = a[i];
        int f = 0;
        while (x % 2 == 0) {
            x >>= 1;
            f++;
        }
        if (f > 0) {
            groups[f].push_back(i);
        }
    }

    for (; Q--; ) {
        int x;
        scanf("%d", &x);
        if (groups.empty() || x > groups.rbegin()->first) {
            continue;
        }
        map<int, vector<int>> ngroups;
        for (auto& [k, v] : groups) {
            if (x > k) {
                ngroups[k] = v;
                continue;
            }
            for (int i : v) {
                a[i] += 1 << (x - 1);
                if (x - 1 > 0) {
                    ngroups[x - 1].push_back(i);
                }
            }
        }
        groups.swap(ngroups);
    }

    output_vector(a);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney