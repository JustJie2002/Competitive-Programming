/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 00:38:40
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

constexpr int M = 2 * 26 + 10;

struct Trie {
    struct Node {
        Node* nex[M] = {};
        int cnt;
    };
    Node* root;
    unordered_map<char, int> ords;
    int o;
    int ord(char c) {
        if (!ords.count(c)) {
            ords[c] = o++;
        }
        return ords[c];
    }
    Trie() {
        root = new Node();
        o = 0;
    }
    void add(const string& word) {
        Node* head = root;
        for (auto c : word) {
            int od = ord(c);
            if (!head->nex[od]) {
                head->nex[od] = new Node();
            }
            head = head->nex[od];
            head->cnt++;
        }
    }
    int qry(const string& word) {
        Node* head = root;
        for (auto c : word) {
            int od = ord(c);
            if (!head->nex[od]) {
                return 0;
            }
            head = head->nex[od];
        }
        return head->cnt;
    }
};

void workout(int tc) {
    int n, Q;
    scanf("%d%d", &n, &Q);

    Trie t;
    for (int i = 0; i < n; i++) {
        auto s = nxt();
        t.add(s);
    }
    
    for (; Q--; ) {
        auto s = nxt();
        printf("%d\n", t.qry(s));
    }

    for (int i)
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}