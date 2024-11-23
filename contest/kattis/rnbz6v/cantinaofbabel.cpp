/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.29.2024 01:01:16
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

string read() {
    string s;
    getline(cin, s);
    return s;
}

vector<string> cut(string s) {
    s += " ";
    string t;
    vector<string> ans;
    for (auto c : s) {
        if (isspace(c)) {
            ans.push_back(t);
            t.clear();
        } else {
            t += c;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        auto s = read();
        auto a = cut(s);
        auto name = a[0];
        int m = a.size();
        for (int j = 1; j < m; j++) {

        }
    }
}

// ~ Just Jie