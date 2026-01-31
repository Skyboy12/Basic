#include <iostream>

using namespace std;

int main(){
    int n, u, v;
    cin >> n >> u >> v;
    int a[n];
    long long prefixsum[n + 1] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefixsum[i + 1] = prefixsum[i] + a[i];
    }
    long long max = prefixsum[u] - prefixsum[0];
    for(int i = 1; i + u - 1 <= n; i++) {
        for (int length = u; length <= v && i + length - 1 <= n; length++) {
            long long current_sum = prefixsum[i + length - 1] - prefixsum[i - 1];
            if (current_sum > max) {
                max = current_sum;
            }
        }
    }
    cout << max << endl;
    return 0;
}