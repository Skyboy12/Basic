#include <iostream>
#include <string>

using namespace std;

bool flip_flop(string& s) {
    int length = s.length();
    if (s[length - 1] == 'A'){
        s[length - 1] = 'B';
        return true;
    }
    string temp = s.substr(0, length - 1);
    if (temp.empty()) {
        return false;
    }
    bool check = flip_flop(temp);
    if (!check) {
        return false;
    }
    s = temp + 'A';
    return true;
}

bool check(string s){
    return s.find('A') != string::npos && s.find('B') != string::npos;
}

int main() {
    int n;
    cin >> n;
    string s(n, 'A');
    bool check_flip = true;
    while (check_flip) {
        check_flip = flip_flop(s);
        if (check(s)) {
            cout << s << endl;
        }
    }
    return 0;
}