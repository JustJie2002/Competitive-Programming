/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.14.2024 18:24:45
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

string merge(string a, string b) {
    int n = a.size();
    int m = b.size();

    string merged_string;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            merged_string += a[i];
            i++;
        } else {
            merged_string += b[j];
            j++;
        }
    }
    while (i < n) {
        merged_string += a[i];
        i++;
    }
    while (j < m) {
        merged_string += b[j];
        j++;
    }

    return merged_string;
}

constexpr int A = 26;

int ord(char c) {
    return c - 'a';
}

struct Node {
    Node* nex[A];
    int which = -1;
    Node() {}
};

struct Trie {
private:
    Node* root;
    vector<string> dic;

public:
    Trie() {
        root = new Node();
    }

    void add_word(const string& word, int i) {
        Node* node = root;
        for (char c : word) {
            int o = ord(c);
            if (node->nex[o] == nullptr) {
                node->nex[o] = new Node();
            }
            node = node->nex[o];
        }
        node->which = i;
        dic.push_back(word);
    }

    Node* get_root() {
        return root;
    }

    string get_word(int i) {
        return dic[i];
    }
};

pair<string, string> unmerge_brute_force(const string& merged_string, const unordered_set<string>& dic) {
    int n = merged_string.size();

    const auto rec = [&](auto&& self, int i, string& a, string& b) {
        if (i == n) {
            if (dic.contains(a) && dic.contains(b) && merge(a, b) == merged_string)  {
                
            }
        }
    }

}

pair<string, string> unmerge(const string& merged_string, const unordered_set<string>& dictionary) {
    int n = merged_string.size();

    Trie t;
    int which = 0;
    for (const string& word : dictionary) {
        t.add_word(word, which);
        which++;
    }

    Node* root = t.get_root();

    pair<string, string> ans;
    const auto rec = [&](auto&& self, int i, Node* ptr_a, Node* ptr_b, char pre, bool to_a) -> bool {
        if (ptr_a == nullptr) {
            return false;
        }
        if (ptr_b == nullptr) {
            return false;
        }
        if (i == n) {
            if (ptr_a->which != -1 && ptr_b->which != -1) {
                ans.first = t.get_word(ptr_a->which);
                ans.second = t.get_word(ptr_b->which);
                return true;
            }
            return false;
        }

        char c = merged_string[i];
        int o = ord(c);

        if (c < pre) {
            if (to_a) {
                return self(self, i + 1, ptr_a->nex[o], ptr_b, c, to_a);
            } else {
                return self(self, i + 1, ptr_a, ptr_b->nex[o], c, to_a);
            }
        }

        bool result = self(self, i + 1, ptr_a->nex[o], ptr_b, c, true);
        if (result) {
            return true;
        }
        result = self(self, i + 1, ptr_a, ptr_b->nex[o], c, false);
        if (result) {
            return true;
        }
        return false;
    };
    rec(rec, 0, root, root, 'a', false);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a = "jie";
    string b = "anson";
    string merged_string = merge(a, b);

    unordered_set<string> dictionary = {
        "jie",
        "anson",
        "jiea",
        "nson",
        "ji",
        "eanson",
        "jia",
        "enson"
    };

    auto ans = unmerge("asdasda", dictionary);
    if (ans.first.empty() && ans.second.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans.first << " " << ans.second << "\n";
    }
}

// ~ JustJie