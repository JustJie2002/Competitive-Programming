/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 15:49:45
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

void workout(int tc) {
    int n;
    i64 k;
    scanf("%d%lld", &n, &k);

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        dq.push_back(x);
    }

    bool ord = true;
    int m = n;
    while (m != 0 && k) {
        if (m == 1) {
            int a = dq.front();
            if (a <= k) {
                m--;
            }
            break;
        } else {
            int a = dq.front();
            dq.pop_front();
            int b = dq.back();
            dq.pop_back();
            if (ord) {
                if (a <= b) {
                    if (k < 2 * a - 1) {
                        break;
                    }
                    k -= 2 * a - 1;
                    b -= (a - 1);
                    dq.push_back(b);
                    ord = false;
                } else {
                    if (k < 2 * b) {
                        break;
                    }
                    k -= 2 * b;
                    a -= b;
                    dq.push_front(a);
                }
            } else {
                if (b <= a) {
                    if (k < 2 * b - 1) {
                        break;
                    }
                    k -= 2 * b - 1;
                    a -= (b - 1);
                    dq.push_front(a);
                    ord = true;
                } else {
                    if (k < 2 * a) {
                        break;
                    }
                    k -= 2 * a;
                    b -= a;
                    dq.push_back(b);
                }
            }
            m--;
        }
    }

    printf("%d\n", n - m);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie