/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 14:41:54
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

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

constexpr int dir[] {-1, 0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    cin >> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '?') {
                for (int d = 0; d < 4; d++) {
                    int ni = i;
                    int nj = j;
                    while (true) {
                        ni += dir[d];
                        nj += dir[d + 1];
                        if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                            if (s[ni][nj] == '?') {
                                cout << 0 << "\n";
                                return 0;
                            } else if (s[ni][nj] != '.') {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
            } else if (isdigit(s[i][j])) {
                int v = s[i][j] - '0';
                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d];
                    int nj = j + dir[d + 1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < n && s[ni][nj] == '?') {
                        v--;
                    }
                }
                if (v != 0) {
                    cout << 0 << "\n";
                    return 0;
                }
            } else if (s[i][j] == '.') {
                bool good = false;
                for (int d = 0; d < 4 && !good; d++) {
                    int ni = i;
                    int nj = j;
                    while (true) {
                        ni += dir[d];
                        nj += dir[d + 1];
                        if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                            if (s[ni][nj] == '?') {
                                good = true;
                                break;
                            } else if (s[ni][nj] != '.') {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
                if (!good) {
                    cout << 0 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << 1 << "\n";
}

// ~ JustJie