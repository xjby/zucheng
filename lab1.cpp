#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void naive(int n, vector<vector<double>>& mat, vector<double>& vec, vector<double>& res) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            res[j] += mat[i][j] * vec[i];
        }
    }
}


void opt(int n, vector<vector<double>>& mat, vector<double>& vec, vector<double>& res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j] += mat[i][j] * vec[i];
        }
    }
}

int main() {
    int n = 1024;
    vector<vector<double>> mat(n, vector<double>(n));
    vector<double> vec(n);
    vector<double> res1(n, 0), res2(n, 0);

    for (int i = 0; i < n; i++) {
        vec[i] = i * 0.1;
        for (int j = 0; j < n; j++) {
    mat[i][j] = i + j * 0.2;
        }
    }

    // 平凡算法计时
    clock_t start = clock();
    naive(n, mat, vec, res1);
    clock_t end = clock();
    cout << "平凡算法时间: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // 优化算法计时
    start = clock();
    opt(n, mat, vec, res2);
    end = clock();
    cout << "优化算法时间: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
