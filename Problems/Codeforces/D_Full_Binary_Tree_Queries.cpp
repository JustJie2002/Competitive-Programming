/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.16.2023 14:13:25
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

constexpr int N = 62;
i64 pw2[N];
i64 rot1[N], rot2[N];

void Init() {
    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = pw2[i - 1] * 2LL;
    }
}

int main() {
    Init();
    int Q;
    scanf("%d", &Q);

    auto get_level = [&](i64 x) -> int {
        return floor(log2(x));
    };

    auto norm = [&](i64 x, i64 mod) -> i64 {
        x %= mod;
        if (x < 0) {
            x += mod;
        }
        return x;
    };

    for (; Q--; ) {
        int op; 
        i64 x;
        scanf("%d%lld", &op, &x);
        int cur_level = get_level(x);

        if (op == 1) {
            i64 k;
            scanf("%lld", &k);
            rot1[cur_level] = norm(rot1[cur_level] + k, pw2[cur_level]);
        } else if (op == 2) {
            i64 k;
            scanf("%lld", &k);
            rot2[cur_level] = norm(rot2[cur_level] + k, pw2[cur_level]);
        } else if (op == 3) {
            i64 cur_pos = norm(x - pw2[cur_level] + rot2[cur_level] + rot1[cur_level], pw2[cur_level]);
            while (x != 1) {
                printf("%lld ", x);
                // move up
                cur_pos /= 2;
                cur_level--;
                x = pw2[cur_level] + norm(cur_pos - rot1[cur_level], pw2[cur_level]);
                cur_pos = pw2[cur_level] + norm(cur_pos - pw2[cur_level] + rot2[cur_level], pw2[cur_level]);
            }
            assert(x == 1);
            puts("1");
        } else {
            assert(false);
        }
    }
}

// ~ Jie ♥ Jenney