/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 00:23:39
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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

constexpr int ord(char c) {
    return c - 'a';
}

constexpr int A = 26;

class Trie {
private:
    struct TNode {
        TNode* nex[A];
        bool is_leaf;
        int cnt;
        i64 rem;
        TNode(): cnt(0), rem(0), is_leaf(false) {}
    };
    TNode* root;

public:
    Trie() { root = new TNode(); }

    void add(string str) {
        reverse(str.begin(), str.end());
        TNode* head = root;
        int n = str.size();
        head->rem += n;
        head->cnt++;
        for (char c : str) {
            int o = ord(c);
            if (head->nex[o] == NULL) {
                head->nex[o] = new TNode();
            }
            head = head->nex[o];
            head->cnt++;
            head->rem += (--n);
        }
        head->is_leaf = true;
    }
    i64 solve(const string& str) {
        TNode* head = root;
        vector<TNode*> stk;
        stk.push_back(head);
        int n = str.size();
        for (char c : str) {
            int o = ord(c);
            if (head->nex[o] == NULL) {
                break;
            }
            head = head->nex[o];
            stk.push_back(head);
        }

        i64 ans = 0;
        i64 pn = 0, pr = 0;
        int m = stk.size();
        n -= (m - 1);
        for (int i = m - 1; i >= 0; i--) {
            TNode* r = stk[i];
            i64 dn = r->cnt - pn;
            i64 dr = r->rem - (pn + pr);
            ans += dr;
            ans += dn * n;
            pn = r->cnt;
            pr = r->rem;
            n++;
        }
        return ans;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vector<string> s(n);
    Trie t;
    for (int i = 0; i < n; i++) {
        s[i] = nxt();
        t.add(s[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 res = t.solve(s[i]);
        ans += res;
    }

    printf("%lld\n", ans);
}

// ~ Jie ♥ Jenney