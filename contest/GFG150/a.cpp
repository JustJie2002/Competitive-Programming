/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 15:08:50
*********************************************/

using i64 = long long;

class Solution {
public:
    bool AreEqual(string s, string t) {
        int n = s.length();

        if (s[0] != t[0] || s.back() != t.back()) {
            return false;
        }
        if (s == t) {
            return true;
        }
        if (s[0] == s.back()) {
            return true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == t[i] && s[i + 1] == t[i + 1] && s[i] == s[0] && s[i + 1] == s.back()) {
                return true;
            }
        }
        return false;
    }
};


// ~ JustJie