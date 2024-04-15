/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.10.2024 11:23:07
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

constexpr int B = 30;

void workout(int tc) {
    int n, s;
    scanf("%d%d", &n, &s);

    if ((s < n) || (n == 1) || (s & 1)) {
        puts("-1");
        return;
    }

    // we can do 1 + 1 + 1 ...
    if (n % 2 == 0) {
        int pre = n - 2;
        int rem = s - pre;
        if (rem % 2 == 0) {
            for (int i = 0; i < n - 2; i++) {
                printf("1 ");
            }
            rem /= 2;
            printf("%d %d\n", rem, rem);
        } else {
            rem++;
            rem /= 2;
            int x = 0, y = 0, z = 0;
            bool turn = true;
            for (int b = 0; b < B; b++) {
                if (rem >> b & 1) {
                    if (turn) {
                        x |= (1 << b);
                        y |= (1 << b);
                    } else {
                        y |= (1 << b);
                        z |= (1 << b);
                    }
                    turn = !turn;
                }
            }
            if (x == 0 || y == 0 || z == 0) {
                puts("-1");
            } else {
                for (int i = 0; i < n - 3; i++) {
                    printf("1 ");
                }
                printf("%d %d %d\n", x, y, z);
            }
        }
    } else {
        int pre = n - 3;
        int rem = s - pre;
        if (rem % 2 == 0) {
            rem /= 2;
            int x = 0, y = 0, z = 0;
            bool turn = true;
            for (int b = 0; b < B; b++) {
                if (rem >> b & 1) {
                    if (turn) {
                        x |= (1 << b);
                        y |= (1 << b);
                    } else {
                        y |= (1 << b);
                        z |= (1 << b);
                    }
                    turn = !turn;
                }
            }
            if (x == 0 || y == 0 || z == 0) {
                if (n > 3 && s >= 6 + n - 3) {
                    rem = s - 6 - (n - 5);
                    if (rem % 2 == 0) {
                        rem /= 2;
                        printf("1 2 3 ");
                        for (int i = 0; i < n - 5; i++) {
                            printf("1 ");
                        }
                        printf("%d %d\n", rem, rem);
                    } else {
                        puts("-1");
                    }
                } else {
                    puts("-1");
                }
            } else {
                for (int i = 0; i < n - 3; i++) {
                    printf("1 ");
                }
                printf("%d %d %d\n", x, y, z);
            }
        } else {
            puts("-1");
        }
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