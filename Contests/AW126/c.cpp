/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 18:56:19
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
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

const string X = "DKER EPH VOS GOLNJ ER RKH HNG OI RKH UOPMGB CPH VOS FSQVB DLMM VOS QETH SQB";
const string A = "DKER EPH VOS GOLNJ UKLMH QHNGLNJ A";
const string B = "AB CPH VOS FSQVB DLMM VOS QHNG A";
const string C = "AB";
const string XBX = X + B + X;
const string CB = C + B;
const int XL = X.length(), AL = A.length(), BL = B.length(), CL = C.length();
const int XBXL = XL + BL + XL;
const int CBL = CL + BL;

constexpr i64 inf = 2e18;

constexpr int MAXN = 1e5 + 5;
i64 dp[MAXN];

void init() {
    dp[0] = XL;
    for (int i = 1; i < MAXN; i++) {
        if (dp[i - 1] >= inf / 2) {
            dp[i] = inf;
        } else {
            dp[i] = AL + dp[i - 1] + BL + dp[i - 1] + CL;
        }
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    init();

    auto solve = [&](auto self, int n, i64 k) -> char {
        if (n == 0) {
            return X[k];
        }
        if (k < AL) {
            return A[k];
        }
        k -= AL;
        if (k < dp[n - 1]) {
            return self(self, n - 1, k);
        }
        k -= dp[n - 1];
        if (k < BL) {
            return B[k];
        }
        k -= BL;
        if (k < dp[n - 1]) {
            return self(self, n - 1, k);
        }
        k -= dp[n - 1];
        return C[k];
    };

    for (; Q--; ) {
        int n;
        i64 k;
        scanf("%d%lld", &n, &k);
        k--;

        if (dp[n] <= k) {
            printf(".");
        } else {
            char c;
            for (int i = n; i >= 0; i--) {
                if (i == 0) {
                    c = X[k];
                    break;
                }
                if (k < AL) {
                    c = A[k];
                    break;
                }
                k -= AL;
                if (k < dp[i - 1]) {
                    continue;
                }
                k -= dp[i - 1];
                if (k < BL) {
                    c = B[k];
                    break;
                }
                k -= BL;
                if (k < dp[i - 1]) {
                    continue;
                }
                k -= dp[i - 1];
                c = C[k];
                break;
            }
            printf("%c", c);
        }

    }
    printf("\n");
}

// ~ Jie ♥ Jenney