/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 23:34:11
****************************************************************************************************/
#include "bits/stdc++.h"

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

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;
using Info = array<int, 2>;
using Item = array<int, 3>;

constexpr int LIM = 2e6;
constexpr i64 inf = 1e14 + 5;

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename K, typename V, typename Hash = custom_hash>
using umap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using uset = umap<K, __gnu_pbds::null_type, Hash>;

void work(int tc) {
    int n, W;
    cin >> n >> W;

    vector<int> v(n), w(n);
    cin >> v >> w;

    auto work = [&](int L, int R) {
        int siz = R - L;
        umap<int, Info> res;
        y_combinator(
            [&](auto &&rec, int i, int val, int tot) -> void {
                res[tot] = max(res[tot], {val, val});
                if (i == siz) {
                    return;
                }
                if (tot + w[L + i] <= W) {
                    rec(i + 1, val + v[L + i], tot + w[L + i]);
                }
                rec(i + 1, val, tot);
            }
        )(0, 0, 0);

        vector<Item> g;
        for (const auto& [k, va] : res) {
            g.push_back({k, va[0], va[1]});
        }
        sort(g.begin(), g.end());

        int mx = 0;
        for (auto &[_, v0, v1] : g) {
            mx = max(mx, v0);
            v1 = mx;
        }

        return g;
    };

    int ans = 0;
    int sum = accumulate(v.begin(), v.end(), 0);
    if (n <= 35 && sum >= LIM) {
        auto a = work(0, n / 2);
        auto b = work(n / 2, n);

        int j = b.size() - 1;
        for (const auto& [k, v0, v1] : a) {
            while (b[j][0] > W - k) {
                j--;
            }
            int tot = b[j][2];
            ans = max(ans, tot + v0);
        }
        j = a.size() - 1;
        for (const auto& [k, v0, v1] : b) {
            while (a[j][0] > W - k) {
                j--;
            }
            int tot = a[j][2];
            ans = max(ans, tot + v0);
        }
    } else {
        vector<i64> dp(sum + 1, inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int k = sum - v[i]; k >= 0; k--) {
                if (dp[k] != inf && dp[k] + w[i] <= W) {
                    dp[k + v[i]] = min(dp[k + v[i]], dp[k] + w[i]);
                    ans = max(ans, k + v[i]);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie