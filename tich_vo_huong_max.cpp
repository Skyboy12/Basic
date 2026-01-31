#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int a[n], b[m];
    int dp[n + 1][m + 1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }
    int max_element = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (a[i-1]*b[j-1]) + max(0, dp[i-1][j-1]);
            if (dp[i][j] > max_element) {
                max_element = dp[i][j];
            }
        }
    }
    cout << max_element;
    return 0;
}