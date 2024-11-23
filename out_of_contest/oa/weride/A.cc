/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 09.28.2024 11:18:27
*********************************************/

#ifdef BROKEN_CODE
#include <bits/LC_parser.h>
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

long totalTriplets(vector<int> capacity, long desiredCapcity) {
    map<long, int> seen;
    map<long, int> seen2;
    int n = capacity.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + int(capacity[i] == 0);
    }
    long answer = 0;
    for (int i = n - 2; i >= 0; i--) {
        long pair = 1ll * capacity[i] * capacity[i + 1];
        if (capacity[i] == 0) {
            if (desiredCapcity == 0) {
                answer += i;
                if (i != 0) {
                    answer += n - i - 2;
                }
            }
            continue;
        }

        if (desiredCapcity == 0) {
            int lzero = pre[i] - pre[0];
            int rzero = pre[n] - pre[i + 1];
            if (capacity[i + 1] == 0) {
                answer += i;
            } else {
                answer += lzero;
            }
            if (i - 1 >= 0) {
                if (capacity[i - 1] == 0) {
                    answer += n - i - 2;
                } else {
                    answer += rzero;
                    if (capacity[i + 1] == 0) {
                        answer--;
                    }
                }
            }
            continue;
        }

        if (desiredCapcity % abs(capacity[i]) == 0) {
            long complement = desiredCapcity / capacity[i];
            answer += seen[complement];
        }

        if (pair != 0) {
            if (i < n - 2 && desiredCapcity % abs(pair) == 0) {
                long complement = desiredCapcity / pair;
                answer += seen2[complement];
            }
            if (i < n - 2 && pair * capacity[i + 2] == desiredCapcity) {
                answer--;
            }
            seen2[capacity[i + 1]]++;
        } else {
            continue;
        }
        seen[pair]++;
    }
    return answer;
}

#ifdef BROKEN_CODE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    exec(&Solution::LoveJenney); // CHANGE FOR PROBLEM
}
#endif

// ~ JustJie