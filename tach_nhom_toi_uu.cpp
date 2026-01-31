#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int min_array = 1;
    for (int i = 1; i < n; i++){
        if (a[i] - a[i - 1] > k) {
            min_array++;
        }
    }
    cout << min_array << endl;
    return 0;
}