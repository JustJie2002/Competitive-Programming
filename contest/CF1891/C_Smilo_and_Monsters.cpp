/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 03:50:23
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    i64 acc = 0;
    i64 atk = 0;
    while (i < j) {
        debug(i, j, acc, atk);
        if (acc + a[i] == a[j]) {
            atk += a[i] + 1;
            acc = 0;
            i++, j--;
        } else if (acc + a[i] > a[j]) {
            i64 need = a[j] - acc;
            atk += need + 1;
            acc = 0;
            a[i] -= need;
            j--;
        } else {
            acc += a[i];
            atk += a[i];
            i++;
        }
    }

    debug(atk);

    if (i == j) {
        i64 w = (a[i] + acc) / 2;
        debug(w, acc);
        w -= acc;
        if (w) {
            atk += w;
            acc += w;
            a[i] -= w;
            a[i] -= acc;
        }
        if (acc) {
            atk++;
        }
        if (a[i]) {
            atk++;
        }
    }

    printf("%lld\n", atk);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney