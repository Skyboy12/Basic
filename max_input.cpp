#include <iostream>

using namespace std;

int main() {
    long long n, max = 0;
    while (cin >> n) {
        if (n > max) {
            max = n;
        }
    }
    cout << max << endl;
    return 0;
}