/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 15:42:56
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

constexpr int MAX_SIZE = 6;

int main() {
    int n;
    scanf("%d", &n);

    vector<string> str(n);
    vector<map<int, int>> freq(MAX_SIZE);
    i64 ans = 0;
    for (auto &s : str) {
        s = nxt();
        int m = s.size();
        vector<int> pre(m + 1);
        for (int i = 0; i < m; i++) {
            pre[i + 1] = pre[i] + (s[i] - '0');
        }
        for (int i = 0; i <= m; i++) {
            int pre_sum = pre[i];
            int suf_sum = pre.back() - pre_sum;
            int L = i, R = m - i;
            if (pre_sum <= suf_sum || L <= R) {
            } else {
                int d = L - R;
                ans += freq[d][pre_sum - suf_sum];
            }
            if (suf_sum <= pre_sum || R <= L) {
            } else {
                int d = R - L;
                ans += freq[d][suf_sum - pre_sum];
            }
        }
        freq[m][pre.back()]++;
    }

    for (int sz = 1; sz < MAX_SIZE; sz++) {
        freq[sz].clear();
    }

    for (int i = n - 1; i >= 0; i--) {
        auto s = str[i];
        int m = s.size();
        vector<int> pre(m + 1);
        for (int j = 0; j < m; j++) {
            pre[j + 1] = pre[j] + (s[j] - '0');
        }
        for (int j = 0; j <= m; j++) {
            int pre_sum = pre[j];
            int suf_sum = pre.back() - pre_sum;
            int L = j, R = m - j;
            if (pre_sum <= suf_sum || L <= R) {
            } else {
                int d = L - R;
                ans += freq[d][pre_sum - suf_sum];
            }
            if (suf_sum <= pre_sum || R <= L) {
            } else {
                int d = R - L;
                ans += freq[d][suf_sum - pre_sum];
            }
        }
        freq[m][pre.back()]++;
    }

    printf("%lld\n", ans);
}

// ~ Jie ♥ Jenney