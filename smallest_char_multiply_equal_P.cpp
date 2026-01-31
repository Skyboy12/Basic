#include <iostream>

using namespace std;
using ll = long long;

int check(int numchar[10]) {
    for (int i = 2; i <= 9; i++) {
        if (numchar[i] > 0) {
            return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll P;
        cin >> P;
        int numchar[10] = {0};
        for (int i = 9; i >=2; i--){
            while (P % i == 0) {
                numchar[i]++;
                P /= i;
            }
        }
        if (P != 1) {
            cout << -1 << endl;
            continue;
        } else {
            if (check(numchar) == 0) {
                cout << 1 << endl;
                continue;
            }
            for (int i = 2; i <= 9; i++) {
                while (numchar[i] > 0) {
                    cout << i;
                    numchar[i]--;
                }
            }
            cout << endl;
        }
    }
    return 0;
}