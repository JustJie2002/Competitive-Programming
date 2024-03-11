
vector<int> manacher(const string& s) { // r[i] - the max size pal centered at i
    string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();

    vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }

    // for (int i = 0; i < n; i++) { // norm
    //     if (i % 2 == 0) {
    //         r[i] = (r[i] - 1) / 2;
    //     } else {
    //         r[i] /= 2;
    //     }
    // }
    return r;
}
