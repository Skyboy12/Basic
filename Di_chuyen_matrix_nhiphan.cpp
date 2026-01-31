#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1){
        int input;
        cin >> input;
        cout << input;
        return 0;
    }
    vector<vector<char>> arr(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            arr[i][j] = (char)('0' + input);
        }
    }

    vector<vector<string>> dp(n, vector<string>(n));
    dp[0][0] = string(1, arr[0][0]);
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + arr[0][i];
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }

    string output = dp[n - 1][n - 1];
    int length = output.length();
    while (length % 4 != 0) {
        output = '0' + output;
        length++;
    }

    string ans = "";
    for (int i = 0; i < length; i += 4) {
        int value = (output[i] - '0') * 8 + (output[i + 1] - '0') * 4 + (output[i + 2] - '0') * 2 + (output[i + 3] - '0');
        if (value < 10) {
            ans += (char)('0' + value);
        } else {
            ans += (char)('A' - 10 + value);
        }
    }
    cout << ans;
    return 0;
}