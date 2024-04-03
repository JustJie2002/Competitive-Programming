/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.05.2024 09:47:10
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

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
using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;

using i64 = long long;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int mex = 0;
    auto b = a;
    sort(b.begin(), b.end());
    HashMap<int, int> freq;
    for (int x : b) {
        if (x == mex) {
            mex++;
        }
        freq[x]++;
    }
    int cmex = mex;
    auto rfreq = freq;

    vector<int> pre(n), suf(n);
    for (int i = n - 1; i >= 0; i--) {
        pre[i] = mex;
        freq[a[i]]--;
        if (freq[a[i]] == 0 && a[i] < mex) {
            mex = a[i];
        }
    }
    mex = cmex;
    swap(rfreq, freq);
    for (int i = 0; i < n; i++) {
        suf[i] = mex;
        freq[a[i]]--;
        if (freq[a[i]] == 0 && a[i] < mex) {
            mex = a[i];
        }
    }

    dbg(pre, suf);

    for (int i = 0; i < n - 1; i++) {
        if (pre[i] == suf[i + 1]) {
            puts("2");
            printf("1 %d\n", i + 1);
            printf("%d %d\n", i + 2, n);
            return;
        }
    }
    puts("-1");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie