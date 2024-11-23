
template<class T>
vector<int> z_function(const T& a) {
    int n = a.size();
    vector<int> z(n);
    for (int i = 1, l = -1, r = -1; i < n; i++) {
        z[i] = (i >= r ? 0 : min(r - i, z[i - l]));
        while (i + z[i] < n && a[i + z[i]] == a[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
