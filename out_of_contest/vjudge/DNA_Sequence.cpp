/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 20:31:13
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

// Credit: Jiangly
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 998'244'353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 100'000;
using Z = MInt<P>;

template<typename T>
struct Matrix {
    int n;
    vector<vector<T>> mat;
    Matrix(int _n): n(_n), mat(n, vector<T>(n)) {}

    // set
    vector<T>& operator[](int row) {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T& operator() (int row, int col) {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    // get
    vector<T> operator[](int row) const {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T operator() (int row, int col) const {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    Matrix operator*(const Matrix& o) {
        assert(n == o.n);
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][k] += mat[i][j] * o[j][k];
                }
            }
        }
        return res;
    }

    constexpr Matrix& operator*=(const Matrix& rhs) & {
        mat = (*this * rhs).mat;
        return *this;
    }

    Matrix pow(i64 b) {
        auto a = *this;
        Matrix<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        for (; b; b /= 2, a *= a) {
            if (b % 2) {
                res *= a;
            }
        }
        return res;
    }

    void out() {
        cout << "DEBUGGING:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " \n"[j == n - 1];
            }
        }
        cout << "END\n";
    }
};

const string DNA = "ATCG";

// Credit: Jiangly
struct AhoCorasick {
    static constexpr int ALPHABET = 4;
    struct Node {
        int len;
        int link;
        bool bad;
        array<int, ALPHABET> next;
        Node() : link{}, next{}, bad(false) {}
    };
    
    vector<Node> t;
    
    AhoCorasick() {
        init();
    }
    
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    
    int add(const vector<int> &a) {
        int p = 1;
        for (auto x : a) {
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        t[p].bad = true;
        return p;
    }

    int ord(char c) {
        return int(find(DNA.begin(), DNA.end(), c) - DNA.begin());
    }
    
    int add(const string &a) {
        vector<int> b(a.size());
        for (int i = 0; i < a.size(); i++) {
            b[i] = ord(a[i]);
        }
        return add(b);
    }
    
    void work() {
        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                } else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }
    
    int next(int p, int x) {
        return t[p].next[x];
    }
    
    int next(int p, char c, char offset = 'a') {
        return next(p, ord(c));
    }
    
    int link(int p) {
        return t[p].link;
    }

    bool is_bad(int p) {
        return t[p].bad;
    }
    
    int len(int p) {
        return t[p].len;
    }
    
    int size() {
        return t.size();
    }
};

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    static string nxt() {
        scanf("%s", buf);
        return buf;
    }
    static char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    static string lxt() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;

int main() {
    int m;
    i64 n;
    scanf("%d%lld", &m, &n);

    AhoCorasick ac;
    for (int i = 0; i < m; i++) {
        auto s = fs.nxt();
        ac.add(s);
    }
    ac.work();
    m = ac.size();

    Matrix<Z> mat(m);
    for (int i = 1; i < m; i++) {
        if (ac.is_bad(i)) {
            continue;
        }
        for (int to = 0; to < ac.ALPHABET; to++) {
            int nxt = ac.next(i, to);
            if (!nxt || ac.is_bad(nxt)) {
                continue;
            }
            mat[i][nxt] += 1;
        }
    }

    auto res = mat.pow(n);
    Z ans = 0;
    for (int i = 1; i < m; i++) {
        ans += res[1][i];
    }

    printf("%d\n", ans.val());
}

// ~ Just Jie