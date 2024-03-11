/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 02:05:34
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

constexpr int MAX_LEN = 20;

int pw[4];

void Init() {
    pw[0] = 1;
    for (int i = 1; i < 4; i++) {
        pw[i] = pw[i - 1] * 26;
    }
}

int ord(char c) {
    return c - 'A';
}

int string_hash(const string& a, const string& b, int k) {
    if (a[k] > b[k])
        return string_hash(b, a, k);
    string sb = a.substr(k, 2) + b.substr(k, 2);
    int hash = 0;
    for (int i = 0; i < 4; i++)
        hash += ord(sb[i]) * pw[i];
    return hash;
}

int main() {
    Init();
    int n;
    scanf("%d", &n);

    map<int, vector<string>> group;
    for (int i = 0; i < n; i++) {
        auto s = nxt();
        int m = s.size();
        group[m].push_back(s);
    }

    int res = 0;
    for (int len = 1; len <= MAX_LEN; len++) {
        const auto& strs = group[len];
        unordered_set<int> exist;

        int m = strs.size();
        for (int i = 0; i < m; i++) {
            auto& a = strs[i];
            for (int j = i + 1; j < m; j++) {
                auto& b = strs[j];
                int dif = 0, p = -1;
                for (int k = 0; k < len; k++) if (a[k] != b[k]) {
                    if (dif == 0) {
                        p = k;
                    } else if (dif == 1) {
                        if (p + 1 != k) {
                            p = -1;
                            break;
                        }
                    } else {
                        p = -1;
                        break;
                    }
                    dif++;
                }

                if (dif != 2 || p == -1) {
                    continue;
                }

                int cur_hash = string_hash(a, b, p);
                if (exist.count(cur_hash)) {
                    res--;
                } else {
                    res++;
                    exist.insert(cur_hash);
                }
            }
        }
    }

    printf("%d\n", res);
}

// ~ Jie ♥ Jenney