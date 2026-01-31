#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s, k;
        cin >> n >> s >> k;
        long long a[n];
        long long f[n+1] = {0};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            f[i+1] = a[i] + f[i];
        }
        if (a[s-1] > k) {
            cout << -1 << endl;
            continue;
        }
        int min_index = s-1;
        for (int i = 0; i < s; i++) {
            if (f[s] - f[i] <= k) {
                min_index = i + 1;
                break;
            }
        }
        cout << min_index << endl;
    }
    return 0;
}