#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int naive(vector<int>& a) {
    int sum = 0;
    for (int x : a)
        sum += x;
    return sum;
}

int twoway(vector<int>& a) {
    int sum1 = 0, sum2 = 0;
    int n = a.size();
    int i = 0;
    for (; i < n - 1; i += 2) {
        sum1 += a[i];
        sum2 += a[i + 1];
    }
    if (i < n)
        sum1 += a[i];
    return sum1 + sum2;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    clock_t start = clock();
    naive(a);
    cout << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    start = clock();
    twoway(a);
    cout << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
