/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.28.2023 10:49:51
****************************************************************************************************/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif
 
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
using Pair = pair<char, int>;

void workout(int tc) {
    int n;
    scanf("%d", &n);
    auto s = nxt();

    if (n & 1) {
        printf("-1\n");
        return;
    }

    int l = 0;
    vector<int> ans;
    deque<char> dq(s.begin(), s.end());
    int cnt = 0;
    while (!dq.empty() && cnt < 301) {
        if (dq.front() != dq.back()) {
            l++;
            dq.pop_front();
            dq.pop_back();
        } else if (dq.front() == '0') {
            ans.push_back(l + int(dq.size()));
            dq.push_back('0');
            dq.pop_front();
            l++;
            cnt++;
        } else {
            ans.push_back(l);
            dq.push_front('1');
            dq.pop_back();
            l++;
            cnt++;
        }
    }

    if (cnt > 300) {
        puts("-1");
    } else {
        printf("%d\n", cnt);
        for (int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
}
 
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}
 
// ~ Jie ♥ Jenney