#include <iostream>
#include <string>
#include <vector>

using namespace std;

char digits[4] = {'2', '3', '5', '7'};
string numberprint;

bool check() {
    bool has2 = false;
    bool has3 = false;
    bool has5 = false;
    bool has7 = false;
    if (numberprint.back() == '2'){
        return false;
    }
    for (char c : numberprint) {
        if (c == '2') has2 = true;
        if (c == '3') has3 = true;
        if (c == '5') has5 = true;
        if (c == '7') has7 = true;
    }
    return has2 && has3 && has5 && has7;
}

void solve(int len, int index) {
    if (index == len) {
        if (check()) {
            cout << numberprint << "\n";
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        numberprint[index] = digits[i];
        solve(len, index + 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++){
        numberprint.resize(i);
        solve(i, 0);
    }

    return 0;
}