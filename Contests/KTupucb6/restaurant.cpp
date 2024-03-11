/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.31.2023 14:19:05
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

using i64 = long long;

int main() {
    int Q;
    while (scanf("%d", &Q), Q) {
        int need_to_wash = 0, ready = 0;
        for (int q = 0; q < Q; q++) {
            auto op = nxt();
            int m;
            scanf("%d", &m);
            if (op == "DROP") {
                need_to_wash += m;
                printf("DROP 2 %d\n", m);
            } else if (op == "TAKE") {
                if (ready < m) {
                    assert(need_to_wash > 0);
                    printf("MOVE 2->1 %d\n", need_to_wash);
                    ready += need_to_wash;
                    need_to_wash = 0;
                }
                ready -= m;
                printf("TAKE 1 %d\n", m);
            } else assert(false);
        }
        printf("\n");
    }
}