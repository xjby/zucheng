#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void naive(int n, vector<vector<int>>& mat, vector<int>& vec, vector<int>& res) {
    for (int j = 0; j < n; j++)
        res[j] = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            res[j] += mat[i][j] * vec[i];
        }
    }
}

void opt(int n, vector<vector<int>>& mat, vector<int>& vec, vector<int>& res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j] += mat[i][j] * vec[i];
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> mat(n, vector<int>(n));
    vector<int> vec(n);
    vector<int> res1(n, 0), res2(n, 0);

    for (int i = 0; i < n; i++) {
        vec[i] = i;
        for (int j = 0; j < n; j++) {
            mat[i][j] = i + j;
        }
    }

    clock_t start = clock();
    naive(n, mat, vec, res1);
    cout << "平凡: " << (double)(clock()-start)/CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    opt(n, mat, vec, res2);
    cout << "优化: " << (double)(clock()-start)/CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
