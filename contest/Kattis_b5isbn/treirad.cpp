/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:26:58
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

constexpr int LIM = int(1e9) + 5;

vector<int> res;

void Init() {
    for (int i = 1; ; i++) {
        int cur = i * (i + 1) * (i + 2);
        if (cur >= LIM) break;
        res.push_back(cur);
    }
}

int main() {
    Init();
    
    int n;
    scanf("%d", &n);

    printf("%d\n", int(lower_bound(res.begin(), res.end(), n) - res.begin()));
}

// ~ Just Jie