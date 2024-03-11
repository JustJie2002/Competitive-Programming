/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.08.2024 21:36:09
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    string nxt() {
        scanf("%s", buf);
        return buf;
    }
    char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    string lst() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;

using i64 = long long;
using i128 = __int128_t;

int main() {
    i64 N, K, M, D;
    scanf("%lld%lld%lld%lld", &N, &K, &M, &D);

    i64 ans = 0;
    for (int d = 0; d < D; d++) {
        if (d > N / K) {
            break;
        }
        i64 cows = 1LL * d * K + 1;
        i64 per_feed = min(M, N / cows);
        debug(cows, per_feed);
        ans = max(ans, per_feed * (d + 1));
    }

    printf("%lld\n", ans);
}

// ~ Just Jie