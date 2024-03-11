
i64 inv_mod(i64 a, i64 m) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    i64 g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        i64 q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    assert(g == 1);
    assert(abs(y) == m);
    return x < 0 ? x + m : x;
}

// Returns a number that is a1 mod m1 and a2 mod m2. Assumes m1 and m2 are relatively prime.
i64 chinese_remainder_theorem(i64 a1, i64 m1, i64 a2, i64 m2) {
    if (m1 < m2) {
        return chinese_remainder_theorem(a2, m2, a1, m1);
    }

    // assert(__gcd(m1, m2) == 1);
    assert(m1 >= m2);
    i64 k = (a2 - a1) % m2 * inv_mod(m1, m2) % m2;
    i64 result = a1 + k * m1;

    if (result < 0) {
        result += m1 * m2;
    }

    assert(0 <= result && result < m1 * m2);
    assert(result % m1 == a1 && result % m2 == a2);
    return result;
}

template<typename T> i64 chinese_remainder_theorem(const vector<T> &a, const vector<T> &m) {
    assert(a.size() == m.size());
    i64 result = a.front();
    i64 mod = m.front();

    for (int i = 1; i < int(m.size()); i++) {
        result = chinese_remainder_theorem(result, mod, a[i], m[i]);
        mod *= m[i];
    }

    return result;
}
