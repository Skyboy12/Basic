#include <iostream>
using namespace std;

int binary_search(int a[], int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == k) return m + 1;
        if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int a[100005];
        for (int i = 0; i < n; ++i) cin >> a[i];
        int pos = binary_search(a, n, k);
        if (pos == -1) cout << "NO\n";
        else cout << pos << '\n';
    }
    return 0;
}