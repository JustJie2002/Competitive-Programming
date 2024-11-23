/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 17:00:53
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
using Info = array<int, 2>;

void work(int tc) {
    int n, M;
    cin >> n >> M;

    vector<Info> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i][0];
    }
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'R') {
            r[i][1] = 1;
        } else {
            r[i][1] = -1;
        }
    }

    vector<vector<int>> par(2);
    for (int i = 0; i < n; i++) {
        par[r[i][0] & 1].push_back(i);
    }

    vector<int> marked(n, -1);
    for (auto &e : par) {
        sort(e.begin(), e.end(), [&](int i, int j) {
            return r[i][0] < r[j][0];
        });

        int m = e.size();
        vector<int> rem;
        for (int i = 0; i < m; i++) {
            int y = e[i];
            if (rem.empty()) {
                rem.push_back(y);
                continue;
            }
            int x = rem.back();
            if (r[x][1] == 1 && r[y][1] == -1) {
                marked[x] = marked[y] = (r[y][0] - r[x][0]) / 2;
                rem.pop_back();
            } else {
                rem.push_back(y);
            }
        }
        m = rem.size();
        vector<int> rem2;
        for (int i = 0; i < m - 1; i++) {
            int x = rem[i];
            int y = rem[i + 1];
            if (marked[x] != -1) {
                continue;
            }

            if (r[x][1] == -1) {
                if (r[x][1] == r[y][1]) {
                    marked[x] = marked[y] = r[x][0] + (r[y][0] - r[x][0]) / 2;
                } else {
                    rem2.push_back(x);
                    break;
                }
            } else {
                break;
            }
        }
        for (int i = m - 1; i > 0; i--) {
            int x = rem[i - 1];
            int y = rem[i];
            if (marked[y] != -1) {
                continue;
            }

            if (r[y][1] == 1) {
                if (r[x][1] == r[y][1]) {
                    marked[x] = marked[y] = (M - r[y][0]) + (r[y][0] - r[x][0]) / 2;
                } else {
                    rem2.push_back(y);
                    break;
                }
            } else {
                break;
            }
        }
        assert(rem2.size() <= 2);
        if (rem2.size() == 2) {
            int x = rem2[0];
            int y = rem2[1];
            if (r[x][0] <= (M - r[y][0])) {
                int t = r[x][0];
                r[x][0] = 0;
                r[y][0] += t;
                marked[x] = marked[y] = t + (M - r[y][0]) + (r[y][0] - r[x][0]) / 2;
            } else {
                int t = (M - r[y][0]);
                r[y][0] = M;
                r[x][0] -= t;
                marked[x] = marked[y] = t + r[x][0] + (r[y][0] - r[x][0]) / 2;
            }
        }
    }

    cout << marked << "\n";
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