/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.03.2024 16:56:29
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

const string OPTIONS = "()";

int main() {
    int n;
    scanf("%d", &n);

    if (n & 1) {
        return 0;
    }

    string s;
    y_combinator([&](auto&& dfs, int idx, int open) -> void {
        if (open < 0) {
            return;
        }
        if (idx == n) {
            if (open == 0) {
                printf("%s\n", s.c_str());
            }
            return;
        }

        // prune
        int rem = n - idx;
        if (open > rem) {
            return;
        }
        if ((rem - open) & 1) {
            return;
        }

        for (auto op : OPTIONS) {
            s += op;
            dfs(idx + 1, open + (op == '(' ? +1 : -1));
            s.pop_back();
        }
    })(0, 0);
}

// ~ Just Jie