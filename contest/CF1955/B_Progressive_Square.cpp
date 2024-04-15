/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 15:43:43
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

constexpr int N = 501;

int aa[N][N];

void workout(int tc) {
    int n, c, d;
    scanf("%d%d%d", &n, &c, &d);

    map<int, int> freq;
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i && j) {
                if (aa[i][j - 1] + d != aa[i - 1][j] + c) {
                    puts("NO");
                    return;
                }
                aa[i][j] = aa[i - 1][j] + c;
            } else if (i) {
                aa[i][j] = aa[i - 1][j] + c;
            } else if (j) {
                aa[i][j] = aa[i][j - 1] + d;
            } else {
                aa[0][0] = freq.begin()->first;
            }
            int x = aa[i][j];
            if (!freq[x]) {
                puts("NO");
                return;
            }
            freq[x]--;
        }
    }

    puts("YES");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie