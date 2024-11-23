/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 13:36:01
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

int ask(const string& s) {
    cout << s << endl;
    string a, b, t;
    cin >> a >> b;
    if (b == "GRANTED") {
        return inf;
    }
    cin >> t >> a;
    t = t.substr(1);
    return stoi(t);
}

void work() {
    string s = "a";
    int t = 5;
    while (true) {
        t = ask(s);
        if (t == 5) {
            s += "a";
        } else {
            break;
        }
    }

    if (t == inf) {
        return;
    }

    for (int i = 0; i < s.size() && t != inf; i++) {
        char p = s[i];
        bool good = false;
        for (char c = 'a'; c <= 'z'; c++) {
            s[i] = c;
            int nt = ask(s);
            if (t > nt) {
                s[i] = p;
                good = true;
                break;
            } else if (nt > t) {
                t = nt;
                good = true;
                break;
            }
        }
        for (char c = 'A'; c <= 'Z' && !good; c++) {
            s[i] = c;
            int nt = ask(s);
            if (t > nt) {
                s[i] = p;
                good = true;
                break;
            } else if (nt > t) {
                t = nt;
                good = true;
                break;
            }
        }
        for (char c = '0'; c <= '9' && !good; c++) {
            s[i] = c;
            int nt = ask(s);
            if (t > nt) {
                s[i] = p;
                good = true;
                break;
            } else if (nt > t) {
                t = nt;
                good = true;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie