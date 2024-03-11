
vector<string> div(string s, char delim = ' ') {
    s += delim;
    vector<string> bucket;
    string t;
    for (char c : s) {
        if (c != delim) {
            t += c;
        } else if (!t.empty()) {
            bucket.push_back(t);
            t.clear();
        }
    }
    return bucket;
}
