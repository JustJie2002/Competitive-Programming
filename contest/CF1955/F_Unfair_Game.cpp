/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 16:17:33
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

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

constexpr int N = 4;
int a[N];
vector<int> win;

void workout(int tc) {
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // 1 ^ 2 = 3
    // 1 ^ 3 = 2
    // 1 ^ 4 = 5
    // 2 ^ 3 = 1
    // 2 ^ 4 = 6
    // 3 ^ 4 = 7

    // technically, we only care about making each values frequency odd or even since at the end it'll be 0 or itself

    int ans = a[3] / 2;
    sort(a, a + N - 1);
    int x = a[0] & 1;
    int y = a[1] & 1;
    int z = a[2] & 1;
    if (x == 1 && y == 1 && z == 1) {
        ans++;
        a[0]--;
        a[1]--;
        a[2]--;
    } else {
        if (x == 1) {
            a[0]--;
        }
        if (y == 1) {
            a[1]--;
        }
        if (z == 1) {
            a[2]--;
        }
    }
    int d = a[2] - a[1];
    ans += d / 2;
    d = a[1] - a[0];
    ans += d;
    d = a[0];
    ans += d / 2 * 3;
    printf("%d\n", ans);
}

void Init() {
    for (int msk = 0; msk < (1 << N); msk++) {
        int x = 0;
        for (int i = 0; i < N; i++) {
            if (msk >> i & 1) {
                x ^= (i + 1);
            }
        }
        if (x == 0) {
            win.push_back(msk);
        }
    }
}

int main() {
    Init();
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie