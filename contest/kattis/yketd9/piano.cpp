/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 22:36:46
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

using i64 = long long;
using Info = pair<int, int>;

constexpr int LIM = 105;

void work(int tc) {
    int n, p;
    cin >> n >> p;
    p /= 2;

    vector<Info> events(n);
    cin >> events;

    vector<int> d[LIM] {};
    for (int i = 1; auto [s, e] : events) {
        d[s].push_back(i);
        d[e + 1].push_back(-i);
        i++;
    }

    set<Info> req;
    for (int i = 0; i < LIM; i++) {
        for (int x : d[i]) {
            if (x > 0) {
                req.emplace(events[x - 1].second, x);
            } else {
                x = -x;
                if (req.contains(pair(events[x - 1].second, x))) {
                    cout << "serious trouble\n";
                    return;
                }
            }
        }
        for (int t = 0; t < p && !req.empty(); t++) {
            req.erase(req.begin());
        }
    }

    req.clear();
    for (int i = 0; i < LIM; i++) {
        for (int x : d[i]) {
            if (x > 0) {
                req.emplace(events[x - 1].second, x);
            } else {
                x = -x;
                if (req.contains(pair(events[x - 1].second, x))) {
                    cout << "weekend work\n";
                    return;
                }
            }
        }
        if (i % 7 >= 5) {
            continue;
        }
        for (int t = 0; t < p && !req.empty(); t++) {
            req.erase(req.begin());
        }
    }

    cout << "fine\n";
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