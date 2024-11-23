/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 18:12:45
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename K, typename V, typename Hash = custom_hash>
using umap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using uset = umap<K, __gnu_pbds::null_type, Hash>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    umap<int, int> occs;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        occs[x]++;
    }

    vector<array<int, 2>> freq {{0, 0}};
    for (const auto &[k, v] : occs) {
        freq.push_back({v, 1});
    }

    sort(freq.begin(), freq.end());

    while (freq.size() > 1) {
        auto [x, v] = freq.back();
        freq.pop_back();
        while (freq.back()[0] == x) {
            v++;
            freq.pop_back();
        }
        auto [wx, _] = freq.back();
        int d = x - wx;
        i64 nk = 1LL * d * v;
        if (k < nk) {
            i64 w = k / v;
            freq.push_back({x - w, v});
            break;
        }
        freq.back()[1] += v;
        k -= nk;
    }
    
    cout << freq.back()[0] << "\n";
}

// ~ Just Jie