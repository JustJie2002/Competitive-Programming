/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 18:23:45
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

void workout(int tc) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);

    // l = k * a^x * b^y

    int cura = 1, ans = 0;
    HashSet<int> s;
    for (int cura = 1; cura <= l; cura *= a) {
        for (int curb = 1; curb <= l / cura; curb *= b) {
            if (l % (cura * curb) == 0) {
                s.insert(l / (cura * curb));
            }
        }
    }

    printf("%zu\n", s.size());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie