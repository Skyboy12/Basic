#include <iostream>

using namespace std;

int main(){
    int a, k, n;
    cin >> a >> k >> n;
    int begin = k - (a % k);
    if (begin + a > n){
        cout << -1 ;
    } else {
        int i;
        for (i = begin; i + a <= n; i += k) {
            cout << i << " ";
        }
    }
    return 0;
}