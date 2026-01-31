#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int dp[n + 1]= {1};
    int maxLength = 1;
    for (int i = 1; i < n; i++){
        dp[i] = 1;
        for (int j = 1; j < m; j++){
            long long x1 = (long long)(a[i] * b[j-1]);
            long long x2 = (long long)(a[i-1] * b[j]);
            if (x1 == x2){
                dp[i] = max(dp[i], dp[i-1] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    cout << maxLength;
    return 0;
}