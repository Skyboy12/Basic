#include <iostream>

using namespace std;

int a[505][505];
int dp[506][506];

int min(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

void check_solve(int n, int m){
    for (int i = 0; i<= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i+1][j+1] = a[i][j];
        }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (a[i][j] == 0) continue;
            dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1;
        }
    }
    int max = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            // cout << dp[i][j] << " ";
            if (dp[i][j] > max) max = dp[i][j];
        }
        // cout << endl;
    }
    cout << max << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        check_solve(n, m);
    }
    return 0;
}