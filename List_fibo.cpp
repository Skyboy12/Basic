#include <iostream>

using namespace std;

long long fibo[100];

void fibo_run() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 100; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main() {
    fibo_run();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            cout << fibo[i] << " ";
        }
        cout << endl;
    }
    return 0;
}