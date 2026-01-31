#include <iostream>
#include <string>

using namespace std;

int main() {
    string binary;
    cin >> binary;
    int test;
    cin >> test;
    int length = binary.length();
    bool dp[length][length];
    for (int i = 0; i < length; i++){
        dp[i][i] = true;
        if (binary[i] == binary[i + 1]) {
            dp[i][i + 1] = true;
        } else {
            dp[i][i + 1] = false;
        }
    }
    for (int len = 3; len <= length; len++) {
        for (int i = 0; i <= length - len; i++) {
            int j = i + len - 1;
            if (binary[i] == binary[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            } else {
                dp[i][j] = false;
            }
        }
    }
    while (test--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (dp[l][r]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}