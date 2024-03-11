/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.07.2024 00:16:37
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
using Coordinate = pair<int, int>;
using Info = pair<Coordinate, int>;

#define f   first
#define s   second

const char PERSON = '@';
const char WALL = '#';
const char EMPTY = '.';

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

constexpr int dir[] = {0, 1, 0, -1, 0};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        Coordinate me;
        int keys = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == PERSON) {
                    me = pair(i, j);
                    grid[i][j] = EMPTY;
                } else if (islower(grid[i][j])) {
                    keys++;
                }
            }
        }

        queue<Info> q;
        int d = 0;

        HashSet<i64> h;

        auto add = [&](const Coordinate& pos, int key_mask) -> void {
            i64 encrypted = key_mask * 10000 + pos.f * 100 + pos.s;
            if (h.find(encrypted) == h.end()) {
                h.insert(encrypted);
                q.push({pos, key_mask});
            }
        };
        auto good = [&](int i, int j) {
            if (i < 0 || i >= n) {
                return false;
            }
            if (j < 0 || j >= m) {
                return false;
            }
            return grid[i][j] != WALL;
        };

        add(me, 0);
        while (!q.empty()) {
            int Q = q.size();
            for (; Q--; ) {
                auto [pos, key_mask] = q.front();
                q.pop();

                if (key_mask == (1 << keys) - 1) {
                    return d;
                }

                for (int k = 0; k < 4; k++) {
                    int new_i = pos.f + dir[k];
                    int new_j = pos.s + dir[k + 1];
                    if (!good(new_i, new_j)) {
                        continue;
                    }
                    const auto& nex = grid[new_i][new_j];
                    if (nex == EMPTY) {
                        add(pair(new_i, new_j), key_mask);
                    } else if (isupper(nex)) {
                        int o = nex - 'A';
                        if (key_mask >> o & 1) {
                            add(pair(new_i, new_j), key_mask);
                        }
                    } else {
                        assert(islower(nex));
                        int o = nex - 'a';
                        add(pair(new_i, new_j), key_mask | (1 << o));
                    }
                }
            }
            d++;
        }

        return -1;
    }
};

constexpr int N = 100;
char s[N];

int main() {
    freopen("input.txt", "r", stdin);

    vector<string> grid;
    while (~scanf("%s", s)) {
        grid.push_back(s);
    }

    Solution solution;
    cout << solution.shortestPathAllKeys(grid) << "\n";
}

// ~ Just Jie