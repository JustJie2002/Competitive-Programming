
struct Manacher {
    string word;
    vector<int> man;
    int pal_count;

    Manacher() {
        word += '#';
    }

    void add(const string& s) {
        for (char c : s) {
            word += c;
            word += '#';
        }
    }

    char _get(int pos) {
        return word[pos];
    }

    void work() {
        int n = word.length();
        man.resize(n);
        pal_count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (2 * j - i >= 0 && j + man[j] > i) {
                man[i] = min(man[2 * j - i], j + man[j] - i);
            }
            while (i - man[i] >= 0 && i + man[i] < n && _get(i - man[i]) == _get(i + man[i])) {
                man[i] += 1;
            }
            if (i + man[i] > j + man[j]) {
                j = i;
            }
            pal_count += man[i] / 2;
        }
    }

    int count_pal() {
        return pal_count;
    }

    int get(int mid, bool odd) {
        return man[2 * mid + !odd + 1] - 1;
    }

    bool is_pal(int l, int r) {
        int sz = r - l + 1;
        int mid = (l + r) / 2;
        int len = get(mid, sz & 1);
        return sz <= len;
    }
};

