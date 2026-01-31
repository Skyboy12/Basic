#include <iostream>

using namespace std;

const int mod = 1000000007;

int main() {
    int number, sides, target;
    cin >> number >> sides >> target;
    int dp[number + 1][target + 1] = {0};
    for (int i = 1; i <= number; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= target; j++) {
            dp[i][j] = 0;
            for (int k = 1; k <= sides && k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    cout << dp[number][target] << endl;
    return 0;
}