
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

template <char MIN_CHAR = 'a'>
struct CompressedTrie {
    struct Info {
        HashMap<int, Info*> nex;
        // TODO: attributes
        void update(...) {
            // TODO: add params and code
        }
        Info* move(int pos) {
            assert(nex.find(pos) != nex.end());
            return nex[pos];
        }
        Info* norm(int pos) {
            if (nex.find(pos) == nex.end())
                nex[pos] = new Info();
            return nex[pos];
        }
    };

    Info* root = NULL;
    Trie() { root = new Info(); }
    constexpr int ord(char c) { return c - MIN_CHAR; }

    void add(const string& word) {
        Info* ptr = root;
        for (char c : word) {
            int o = ord(c);
            ptr->norm(o);
            // TODO: update node
        }
    }

    int query(const string& query_word) {
        Info* ptr = root;
        for (char c : query_word) {
            int o = ord(c);
            // TODO: find answer
            ptr = ptr->move(o);
        }
        return -1;
    }
};
