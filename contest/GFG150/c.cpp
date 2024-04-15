/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 15:09:15
*********************************************/

using i64 = long long;

constexpr int A = 10;

class Solution {
  public:
    vector<int> substringsAndPermutations(int n, int m, string s, vector<string>& str) {
        auto ord = [&](char c) {
            return c - '0';
        };
        vector<array<int, A>> pre(n + 1);
        pre[0] = {};
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            pre[i + 1][ord(s[i])]++;
        }

        auto issoke = [&](int i, const auto& occs) {
            for (int a = 0; a < A; a++) {
                if (pre[i + 1][a] < occs[a]) {
                    return false;
                }
            }
            return true;
        };

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            array<int, A> occs {};
            for (char c : str[i]) {
                occs[ord(c)]++;
            }

            if (!issoke(n - 1, occs)) {
                ans[i] = -1;
                continue;
            }

            int lo = 0, hi = n - 1, mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (issoke(mid, occs)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            ans[i] = hi + 1;
        }

        return ans;
    }
};

// ~ JustJie