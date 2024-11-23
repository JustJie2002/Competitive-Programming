/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.03.2024 17:29:02
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    vector<int> points;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && a[j] - a[i] <= r) {
            j++;
        }
        j--;
        points.push_back(a[j]);
        while (j < n && a[j] - points.back() <= r) {
            j++;
        }
        dbg(i, j);
        i = j;
    }

    printf("%zu\n", points.size());
    for (int x : points) {
        printf("%d ", x);
    }
}

// ~ Just Jie