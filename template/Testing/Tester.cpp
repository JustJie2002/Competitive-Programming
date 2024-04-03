/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.04.2024 18:43:16
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int main() {
    Matrix<int> mat(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat[i][j] = 1;
        }
    }
    Matrix<int> mat2(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mat2[i][j] = 1;
        }
    }
    auto matm = mat * mat2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matm[i][j] << " \n"[j == 1];
        }
    }
}

// ~ Just Jie