#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int result = -1;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == k) {
                result = 1;
            }
        }
        if (result == 1) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < n - 1; i++){
            if (arr[i] % k == 0) {
                int current_gcd = arr[i];
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] % k == 0) {
                        current_gcd = gcd(current_gcd, arr[j]);
                        if (current_gcd == k) {
                            if (j - i + 1 < result || result == -1)
                                result = j - i + 1;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        cout << result << endl;
    }
}