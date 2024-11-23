/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 10:59:38
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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

void work(int tc) {
    int n, m;
    cin >> n >> m;

    vector mat1(n, vector<int>(m));
    vector mat2(n, vector<int>(m));
    cin >> mat1 >> mat2;

    auto check = [&](auto a, auto b) {
        for (int i = 0; i < a.size(); i++) {
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    };

    bool good = check(mat1, mat2);

    vector<vector<int>> new_mat1(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_mat1[j].push_back(mat1[i][j]);
        }
    }
    vector<vector<int>> new_mat2(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_mat2[j].push_back(mat2[i][j]);
        }
    }

    good = good && check(new_mat1, new_mat2);

    cout << (good ? "YES" : "NO") << "\n";
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