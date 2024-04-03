/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 15:48:45
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

constexpr int A = 26, INF = int(1e9) + 5;

constexpr int ord(char c) {
    return c - 'a';
}

constexpr int pw2(int pw) {
    return 1 << pw;
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int N = int(2e5) + 5;
char s[N];

int conquer(int L, int R, int a) {
    int siz = R - L + 1;
    for (int i = L; i <= R; i++) {
        if (ord(s[i]) == a) {
            siz--;
        }
    }
    return siz;
}

int divide(int L, int R, int a) {
    int siz = R - L + 1;
    if (siz == 1) {
        return int(ord(s[L]) != a);
    }
    int M = L + siz / 2;
    return min(
        divide(L, M - 1, a + 1) + conquer(M, R, a),
        divide(M, R, a + 1) + conquer(L, M - 1, a)
    );
}

void workout(int tc) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    int ans = INF;
    int mid = n / 2;
    ans = min({
        ans, 
        divide(0, mid - 1, 1) + conquer(mid, n - 1, 0),
        divide(mid, n - 1, 1) + conquer(0, mid - 1, 0)
    });

    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie