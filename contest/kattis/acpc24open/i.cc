/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 14:50:06
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int M = 4;

const string COLORS = "RGUB";
constexpr int LIM = (1 << M) - 1;

int get(char c) {
    auto pos = COLORS.find(c);
    assert(pos != string::npos);
    return pos;
}

void work() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            s[i] += c;
        }
    }

    auto has = [&](int mask, int nth) {
        return mask >> nth & 1;
    };

    int ans = 1;
    for (int mask = 0; mask < (1 << M); mask++) {
        // 0: different for all
        // 1: same for all
        bool dif = false;
        for (int i = 0; i < M; i++) {
            if (!has(mask, i)) {
                dif = true;
            }
        }

        if (!dif) {
            for (int i = 0; i < n; i++) {
                int cur = 1;
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) {
                        cur++;
                    }
                }
                ans = max(ans, cur);
            }
        } else {
            int used_mask[M] {};
            int count = 0;
            auto dfs = [&](auto&& self, int j, int i) {
                ans = max(ans, count);
                if (count == M) {
                    return;
                }
                if (j == n) {
                    return;
                }
                self(self, j + 1, i);
                bool met_req = true;
                vector<int> ch;
                for (int k = 0; k < M && met_req; k++) {
                    if (has(mask, k)) {
                        if (count != 0 && s[j][k] != s[i][k]) {
                            met_req = false;
                        }
                    } else {
                        if (has(used_mask[k], get(s[j][k]))) {
                            met_req = false;
                        } else {
                            ch.push_back(k);
                        }
                    }
                }

                if (met_req) {
                    for (int k : ch) {
                        used_mask[k] |= (1 << get(s[j][k]));
                    }

                    count++;
                    self(self, j + 1, (count == 1 ? j : i));
                    count--;

                    for (int k : ch) {
                        used_mask[k] ^= (1 << get(s[j][k]));
                    }
                }
            };
            dfs(dfs, 0, -1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie