/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.08.2024 15:58:11
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Segment = array<int, 2>;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;

    vector<string> p(n);
    cin >> p;
    p.push_back("and");
    n++;

    vector<Segment> bad_pos;
    vector<int> true_pos;
    bool cur = false;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == "and") {
            if (!cur) {

            }
        } else if (p[i] == "or") {
        } else if (p[i] == "false") {
        } else {
            cur = true;
        }
    }

    const auto work = [&](int L, int R) -> void {

    }

    string ans;
    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        ans += work(L, R);
    }

    cout << ans << "\n";
}

// ~ JustJie