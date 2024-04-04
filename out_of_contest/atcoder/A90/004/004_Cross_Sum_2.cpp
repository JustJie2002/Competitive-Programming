/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 00:49:37
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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector aa(n, vector<int>(m));
    vector<int> row_sum(n), col_sum(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &aa[i][j]);
            row_sum[i] += aa[i][j];
            col_sum[j] += aa[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int res = row_sum[i] + col_sum[j] - aa[i][j];
            printf("%d%c", res, " \n"[j == m - 1]);
        }
    }
}

// ~ Just Jie