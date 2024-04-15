/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.10.2024 12:09:42
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
using Info = array<int, 2>;

void workout(int tc) {
    int n, m;
    scanf("%d%d", &m, &n);

    vector<Info> queries(n);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &queries[i][j]);
            queries[i][j]--;
        }
    }

    double deg = 360. / m;

    vector<int> dif(2 * m);
    for (const auto& [a, b] : queries) {
        if (b < a) {
            b += m;
        }
        dif[a]++;
        dif[b]--;
    }

    for (int i = 0; i < 2 * m - 1; i++) {

    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie