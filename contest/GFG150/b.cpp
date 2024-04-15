/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 15:09:03
*********************************************/

using i64 = long long;

class Solution {
  public:
    i64 maxPoints(int n, vector<vector<int>>& a) {
        vector<i64> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int nxt = min(n, i + a[i][1] + 1);
            dp[i] = max(dp[i + 1], dp[nxt] + a[i][0]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// ~ JustJie