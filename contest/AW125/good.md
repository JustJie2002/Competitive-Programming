我们在每个下标看下前面有多少个比目前数大的：
有三种结果： \
- bigger = 1, 那我们把那个比目前数大的那个数给标下来 就说是它"仇人"
- bigger = 0, 我们前面是没有任何比目前的数大的 这个是个good数
- bigger > 1, 因为前面太多数需要删了 所以我们目前可以所把这个下标放弃了

现在我们可以模拟 如果我们把目前这个下标删掉会有几个价值元素 \
目前已知 总共有 good个价值元素 我们先看下目前这个是不是价值元素 如果是我们就得 -1 然后 看下目前这个数是多少个其他数的仇人 然后我们就知道如果我们删掉目前元素 我们会得到 多少个价值元素

```c++
/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 21:01:20
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) {
        ost.insert(make_pair(val, ++freq[val]));
    }
    
    void erase(T val) {
        ost.erase(make_pair(val, freq[val]--));
    }

    int order_of_key(T val) {
        return ost.order_of_key(make_pair(val, -1));
    }
    
    T find_by_order(T val) {
        return ost.find_by_order(val)->first;
    }

    T lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() {
        return ost.size();
    }

    bool empty() {
        return ost.empty();
    }
};

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n <= 2) {
        printf("1\n");
        return 0;
    }

    SortedList<int> perm;
    vector<bool> is_good(n);
    int good = 0;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int j = perm.lower_bound(a[i]);
        int more = perm.size() - j;
        if (more == 1) {
            int big = perm.find_by_order(perm.size() - 1);
            pre[i] = big;
            freq[big]++;
        } else if (more == 0) {
            pre[i] = 0;
            good++;
        }
        perm.add(a[i]);
    }

    int ans = -1, node = 0;
    for (int i = 0; i < n; i++) {
        int aft = good - int(pre[i] == 0) + freq[a[i]];
        if (aft > ans) {
            ans = aft;
            node = a[i];
        } else if (aft == ans) {
            node = min(node, a[i]);
        }
    }

    printf("%d\n", node);
}

// ~ Jie ♥ Jenney
```