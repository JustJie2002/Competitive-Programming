/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 21:38:12
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int A = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const auto ord = [&](char c) {
        return c - 'a';
    };

    string can_use;
    cin >> can_use;
    int good_mask = 0;
    for (auto c : can_use) {
        good_mask |= (1 << ord(c));
    }

    string s;
    cin >> s;
    int n = s.size();

    vector<set<int>> pos(A);
    bool good = true;
    for (int i = 0; auto c : s) {
        pos[ord(c)].insert(i);
        if (!(good_mask & (1 << ord(c)))) {
            good = false;
            break;
        }
        i++;
    }

    int sz = 0;
    int i = -1;
    while (i < n) {
        int lst = -1;
        for (int a = 0; a < A; a++) {
            if (good_mask & (1 << a)) {
                auto it = pos[a].upper_bound(i);
                if (it == pos[a].end()) {
                    lst = n;
                    break;
                }
                lst = max(lst, *it);
            }
        }
        sz++;
        i = lst;
    }

    int q;
    cin >> q;

    while (q--) {
        string t;
        cin >> t;

        if (!good || t.size() != sz) {
            cout << "0\n";
        } else {
            bool res = false;
            int i = -1;
            for (auto c : t) {
                if (!(good_mask & (1 << ord(c)))) {
                    res = false;
                    break;
                }
                const auto& v = pos[ord(c)];
                auto it = v.upper_bound(i);
                if (it == v.end()) {
                    res = true;
                    break;
                }
                i = *it;
            }
            cout << (res ? "1" : "0") << "\n";
        }
    }
}

// ~ Just Jie