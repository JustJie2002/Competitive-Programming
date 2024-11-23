/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 14:20:31
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
using Query = array<int, 2>;

void work(int tc) {
    int n, Q;
    cin >> n >> Q;

    vector<i64> v(n);
    cin >> v;

    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        cin >> queries[q][0];
        queries[q][1] = q;
    }

    sort(queries.begin(), queries.end());

    vector<i64> ans(Q);
    int i = 1;
    i64 a = v[0], b = 0;
    multiset<i64> large, small;
    large.insert(v[0]);
    for (const auto& [k, qi] : queries) {
        for (; i < k; i += 2) {
            b += v[i];
            small.insert(v[i]);
            a += v[i + 1];
            large.insert(v[i + 1]);
            do {
                i64 smallest_of_large = *large.begin();
                i64 largest_of_small = *small.rbegin();
                if (largest_of_small <= smallest_of_large) {
                    break;
                }
                a -= smallest_of_large;
                a += largest_of_small;
                b -= largest_of_small;
                b += smallest_of_large;
                large.erase(large.find(smallest_of_large));
                small.erase(small.find(largest_of_small));
                large.insert(largest_of_small);
                small.insert(smallest_of_large);
            } while (true);
        }
        ans[qi] = a - b;
    }

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