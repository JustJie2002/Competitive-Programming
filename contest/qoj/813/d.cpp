/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 22:49:35
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = pair<int, char>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    map<string, int> mp;
    int id = 0;
    const auto get = [&](string s) {
        if (!mp.contains(s)) {
            mp[s] = id++;
        }
        return mp[s];
    };

    const auto get_eq = [&]() {
        string eq;
        getline(cin, eq);
        eq += " ";
        vector<string> ops;
        string t;
        for (auto c : eq) {
            if (isspace(c)) {
                ops.push_back(t);
                t.clear();
            } else {
                t += c;
            }
        }
        return ops;
    };

    vector<set<Info>> adj(n);
    for (int e = 0; e < m; e++) {
        auto ops = get_eq();
        int i = find(ops.begin(), ops.end(), "=");
        
    }
}

// ~ Just Jie