/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 20:54:10
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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    auto work = [&](const auto& a) -> vector<int> {
        vector<int> lis;
        vector<int> siz(n);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                lis.push_back(a[i]);
                siz[i] = lis.size();
            } else {
                *it = a[i];
                siz[i] = it - lis.begin() + 1;
            }
        }
        return siz;
    };

    auto forward = work(a);
    reverse(a.begin(), a.end());
    for (int& x : a) {
        x = -x;
    }
    auto backward = work(a);
    reverse(backward.begin(), backward.end());
    int lis = *max_element(forward.begin(), forward.end());

    vector<int> ans;
    dbg(forward);
    dbg(backward);
    for (int i = 0; i < n; i++) {
        if (forward[i] + backward[i] - 1 == lis) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << "\n";
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