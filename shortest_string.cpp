#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n = str.size();
        string diff_elements = "";
        int diff_count[256] = {0};
        for (int i = 0; i < n; i++) {
            if (diff_count[str[i]] == 0) {
                diff_elements += str[i];
            }
            diff_count[str[i]]++;
        }
        int m = diff_elements.size();
        int min_length = n;
        int start = 0, end = 0, count = 0;
        int char_count[256] = {0};
        while (end < n) {
            char_count[str[end]]++;
            if (char_count[str[end]] == 1) {
                count++;
            }
            while (count == m) {
                min_length = min(min_length, end - start + 1);
                char_count[str[start]]--;
                if (char_count[str[start]] == 0) {
                    count--;
                }
                start++;
            }
            end++;
        }
        cout << min_length << endl;
    }
    return 0;
}