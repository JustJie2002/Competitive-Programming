/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 10:43:42
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int query(const string& s, char add, bool add_to_back) {
    if (add_to_back) {
        cout << "? " << s << add << endl;
    } else {
        cout << "? " << add << s << endl;
    }
    int res;
    cin >> res;
    return res;
}

void work(int tc) {
    int n;
    cin >> n;

    string ans = "";
    bool adding_to_back = true;
    do {
        if (adding_to_back) {
            if (query(ans, '0', true)) {
                ans += "0";
            } else if (query(ans, '1', true)) {
                ans += "1";
            } else {
                adding_to_back = false;
            }
        }
        if (!adding_to_back) {
            if (query(ans, '0', false)) {
                ans = "0" + ans;
            } else {
                ans = "1" + ans;
            }
        }
    } while (ans.size() != n);

    cout << "! " << ans << endl;
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

// ~ JustJie