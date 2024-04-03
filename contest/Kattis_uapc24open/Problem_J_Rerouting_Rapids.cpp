/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 15:22:41
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
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj(n);
    int root;
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        p--;
        if (p != -1) {
            adj[p].push_back(i);
        } else {
            root = i;
        }
    }

    auto fix = [&](int cutoff) -> bool {
        int left_over = y_combinator([&](auto&& dfs, int cur) -> int {
            int flow = 0;
            for (int nei : adj[cur]) {
                flow += dfs(nei) + 1;
            }

            return max(0, flow - cutoff);
        })(root);
        return left_over == 0;
    };

    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (fix(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", hi);
}

// ~ Just Jie