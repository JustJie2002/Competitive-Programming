/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 11:36:13
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

constexpr int B = 60;

array<i64, 2> divmod(i64 n, i64 k) {
    return {
        n / k,
        n % k
    };
}

void workout(int tc) {
    i64 n, k;
    scanf("%lld%lld", &n, &k);

    if (n - k + 1 <= 0) {
        puts("NO");
        return;
    }

    i64 sum = 0;
    const auto& [a, b] = divmod(n, n - k + 1);
    sum = a + b;

    if (sum != k) {
        puts("NO");
        return;
    }

    puts("YES");
    puts("2");
    printf("%lld 1\n", n - k + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie