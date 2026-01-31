#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int str_len = str.length();
    if (str_len == 0) {
        cout << 0 << endl;
        return 0;
    }
    int max_length = 1;
    int current_length = 1;
    for (int i = 1; i < str_len; i++) {
        if (str[i] >= str[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_length = 1;
        }
    }
    if (current_length > max_length) {
        max_length = current_length;
    }
    cout << max_length << endl;
    return 0;
}