
template<int SIZE = 26, char MIN_CHAR = 'a'>
struct Trie {
    struct Info {
        Info* nex[SIZE];
        // TODO: attributes
        void update(...) {
            // TODO: add params and code
        }
        bool poss(int pos) {
            return nex[pos] ? true : false;
        }
        Info* move(int pos) {
            assert(0 <= pos && pos < SIZE);
            return nex[pos];
        }
        Info* norm(int pos) {
            assert(0 <= pos && pos < SIZE);
            if (!poss(pos))
                nex[pos] = new Info();
            return nex[pos];
        }
    };

    Info* root = NULL;
    Trie() { root = new Info(); }
    constexpr int ord(char c) { return c - MIN_CHAR; }
    constexpr char chr(int o) { return o + MIN_CHAR; }

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