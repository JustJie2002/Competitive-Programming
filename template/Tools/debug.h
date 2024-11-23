
// Credit: tourist
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(const vector<bool>& a) {
    bool f = true;
    string res = "{";
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; i++) {
        if (!f) {
            res += ", ";
        }
        f = false;
        res += to_string(a[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(const bitset<N>& bs) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + bs[i]);
    }
    return res;
}

template <typename A>
string to_string(const A& v) {
    bool f = true;
    string res = "{";
    for (const auto &x : v) {
        if (!f) {
            res += ", ";
        }
        f = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename T, size_t N>
string to_string(const array<T, N>& a) {
    bool f = true;
    string res = "{";
    for (size_t i = 0; i < N; i++) {
        if (!f) {
            res += ", ";
        }
        f = false;
        res += to_string(a[i]);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dbp(...) cout << __VA_ARGS__ << "\n";
