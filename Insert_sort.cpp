#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        cout << "Buoc " << i << ":";
        for (int k = 0; k <= i; k++) cout << " " << a[k];
        cout << endl;
    }
    return 0;
}