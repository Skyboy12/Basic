#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int str_len = str.length();
    if (str_len == 0) {
        cout << 0 << endl;
        return 0;
    }
    int max_length = 1;
    int dp[str_len];
    dp[0] = 1;
    for (int i = 1; i < str_len; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (str[i] >= str[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }
    cout << max_length << endl;
    return 0;
}