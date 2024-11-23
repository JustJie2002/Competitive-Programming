/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 12:07:58
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

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

using Info = array<int, 2>;

void work() {
    int n;
    cin >> n;

    vector<int> s(n), t(n);
    map<int, int> where;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
        where[s[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }

    int ans = 0;
    vector<Info> swaps;
    for (int i = 0; i < n; i++) {
        int p = where[t[i]];
        if (p == i) {
            continue;
        }
        if (t[p] == s[i]) {
            ans++;
            swap(t[i], t[p]);
            swaps.push_back({i + 1, p + 1});
        }
    }

    DSU uf(n);
    for (int i = 0; i < n; i++) {
        if (t[i] == s[i]) {
            continue;
        }
        int p = where[t[i]];
        uf.merge(i, p);
    }

    map<int, vector<int>> f;
    for (int i = 0; i < n; i++) {
        f[uf.find(i)].push_back(i);
    }

    for (const auto& [_, g] : f) {
        int m = g.size();
        if (m == 1) {
            continue;
        }
        for (int i : g) {
            int p = where[t[i]];
            if (i == p) {
                continue;
            }
            swap(t[i], t[p]);
            swaps.push_back({i + 1, p + 1});
            ans++;
        }
    }
    cout << ans << "\n";
    for (const auto& [i, j] : swaps) {
        cout << i << " " << j << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie