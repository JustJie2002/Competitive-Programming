
template <class Info> struct KWindow {
    multiset<Info> s;
    int k;
    Info res = 0;
    typename multiset<Info>::iterator it;

    KWindow() {}
    KWindow(int _k) : k(_k) {}

    void insert(const Info& x) {
        s.insert(x);
        if (s.size() <= k) res += x;
        else if (x < *it) res += x - *(it--);
        if (s.size() == k) it = prev(s.end());
    }

    void erase(const Info& x) {
        if (s.size() <= k) s.erase(s.lower_bound(x)), res -= x;
        else {
            auto it2 = s.lower_bound(x);
            if (!(*it < x)) {
                res += *(++it) - x;
            }
            s.erase(it2);
        } 
    }

    Info get() { return res; }
};

struct Info {
    // TODO
    bool operator<(const Info& rhs) {
        // TODO
    }
};

Info operator+(const Info& a, const Info& b) {
    // TODO
}
