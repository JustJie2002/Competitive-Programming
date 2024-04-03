/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 11:39:46
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

void workout(int tc) {
    auto s = nxt();
    int n = s.size();

    vector<int> upper, lower;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (!lower.empty()) {
                lower.pop_back();
            }
        } else if (s[i] == 'B') {
            if (!upper.empty()) {
                upper.pop_back();
            }
        } else if (islower(s[i])) {
            lower.push_back(i);
        } else {
            upper.push_back(i);
        }
    }

    copy(upper.begin(), upper.end(), back_inserter(lower));
    sort(lower.begin(), lower.end());

    string sb;
    for (int i : lower) {
        sb += s[i];
    }
    printf("%s\n", sb.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney