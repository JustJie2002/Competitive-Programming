/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.10.2024 10:35:30
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
    int n;
    scanf("%d", &n);

    Info a {}, b {};
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[0] += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[1] += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[0] += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[1] += x;
    }

    if (a[0] > b[0] && a[1] > b[1]) {
        puts("A");
    } else if (b[0] > a[0] && b[1] > a[1]) {
        puts("P");
    } else {
        puts("DRAW");
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