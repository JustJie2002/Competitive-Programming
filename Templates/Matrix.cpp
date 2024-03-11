
template <typename T>
struct Matrix {
    int n;
    vector<vector<T>> mat;
    Matrix(int _n): n(_n), mat(n, vector<T>(n)) {}

    // set
    vector<T>& operator[](int row) {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T& operator() (int row, int col) {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    // get
    vector<T> operator[](int row) const {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T operator() (int row, int col) const {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    Matrix operator*(const Matrix& o) {
        assert(n == o.n);
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][k] += mat[i][j] * o[j][k];
                }
            }
        }
        return res;
    }

    constexpr Matrix& operator*=(const Matrix& rhs) & {
        mat = (*this * rhs).mat;
        return *this;
    }

    Matrix pow(i64 b) {
        auto a = *this;
        Matrix<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        for (; b; b /= 2, a *= a) {
            if (b % 2) {
                res *= a;
            }
        }
        return res;
    }

    void out() {
        cout << "DEBUGGING:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " \n"[j == n - 1];
            }
        }
        cout << "END\n";
    }
};
