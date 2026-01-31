#include <iostream>

using namespace std;

int factorial[11];
void factorials() {
    factorial[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
}

int element(int n, int k) {
    return factorial[n] / (factorial[k] * factorial[n - k]);
}

int main() {
    factorials();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << element(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}