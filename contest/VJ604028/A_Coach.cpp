/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.15.2024 01:53:09
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

struct DSU {
    vector<int> par, siz;
    int components;

    DSU() {}
    DSU(int n): components(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

constexpr int N = 3;

vector<int> prep[N + 1];
int cnt[N + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    DSU uf(n);
    for (; m--; ) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        uf.merge(u, v);
    }

    map<int, vector<int>> group;
    for (int i = 0; i < n; i++) {
        int fa = uf.find(i) + 1;
        group[fa].push_back(i + 1);
    }

    for (const auto& [fa, grp] : group) {
        int siz = grp.size();
        if (siz > N) {
            puts("-1");
            return 0;
        }
        prep[siz].push_back(fa);
        cnt[siz]++;
    }

    if (cnt[1] < cnt[2]) {
        puts("-1");
        return 0;
    }
    cnt[1] -= cnt[2];
    if (cnt[1] % 3 != 0) {
        puts("-1");
        return 0;
    }

    for (int t : prep[3]) {
        for (int p : group[t]) {
            printf("%d ", p);
        }
        printf("\n");
    }
    for (int t : prep[2]) {
        for (int p : group[t]) {
            printf("%d ", p);
        }
        int pp = prep[1].back();
        prep[1].pop_back();
        printf("%d\n", pp);
    }
    for (int i = 0; i < cnt[1]; i += 3) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", prep[1][i + j]);
        }
        printf("\n");
    }
}

// ~ Just Jie