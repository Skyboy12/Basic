#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void flip_flop(string &s) {
    int len = s.length();
    if (s[len - 1] == '6'){
        s[len - 1] = '8';
    } else {
        string temp = s.substr(0, len - 1);
        flip_flop(temp);
        s = temp + '6';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; ++i) {
            s += '6';
        }
        n = pow(2, n);
        cout << n << endl;
        n--;
        while (n--) {
            cout << s << " ";
            flip_flop(s);
        }
        cout << s << endl;
    }
}