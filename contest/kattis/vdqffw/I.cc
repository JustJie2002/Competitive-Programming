/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 14:05:57
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Pair = pair<string, int>;

const int mx[] {3, 1, 3, 1, 3, 1, 3};

constexpr i64 inf = i64(1e18) + 10;
const string S = "MDCLXVI";

void work() {
    i64 c[6];
    for (int i = 0; i < 6; i++) {
        cin >> c[i];
    }

    const auto good = [&]() {
        for (int i = 0; i < 6; i++) {
            if (c[i]) {
                return true;
            }
        }
        return false;
    };

    i64 ans = 0;
    vector<Pair> res;
    while (good()) {
        string cur;
        i64 occ = inf;
        int use[6];
        for (int i = 0; i < 6; i++) {
            use[i] = min<int>(c[i], mx[i]);
            if (use[i] != 0) {
                occ = min(occ, c[i] / use[i]);
            }
            cur += string(use[i], S[i]);
        }
        for (int i = 0; i < 6; i++) {
            c[i] -= 1LL * use[i] * occ;
        }
        ans += occ;
        res.push_back({cur, occ});
    }

    cout << ans << "\n";
    cout << res.size() << "\n";
    for (const auto& [s, v] : res) {
        cout << s << " " << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie