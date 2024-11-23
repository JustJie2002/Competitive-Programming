/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 20:46:37
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

namespace reader {
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
};
using namespace reader;

using i64 = long long;
using Info = array<int, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Info> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i][0] >> cards[i][1];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool good = false;
            for (int k = 0; k < 2; k++) {
                if (cards[i][k] == cards[j][k]) {
                    good = true;
                }
            }
            if (good) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    auto bit = [&](int mask, int nth) {
        return mask >> nth & 1;
    };

    const int FULL_MASK = 1 << n;
    vector<bool> dp(FULL_MASK);
    for (int msk = 1; msk < FULL_MASK; msk++) {
        bool win = false;
        for (int i = 0; i < n && !win; i++) if (bit(msk, i)) {
            for (int j : adj[i]) if (bit(msk, j)) {
                if (!dp[msk ^ (1 << j) ^ (1 << i)]) {
                    win = true;
                    break;
                }
            }
        }
        dp[msk] = win;
    }

    cout << (dp.back() ? "Takahashi" : "Aoki") << "\n";
}

// ~ Just Jie