/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.05.2024 11:28:38
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
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);

    int tot = a + b;
    int at_least = tot / n;
    int still_need = tot - at_least * n;
    int res = (b - at_least) + max(0, a - at_least);
    if (still_need == 1 && b > at_least) {
        res--;
    } else if (still_need >= 2) {
        if (b > at_least) {
            res--;
        }
        if (a > at_least) {
            res--;
        }
    }

    printf("%d\n", res);
}

// ~ Just Jie