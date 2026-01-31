#include <iostream>

using namespace std;
main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k = 0;
        cin >> n;
        int a[n]; int b[n];
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            int found = false;
            for (int j = 0; j < k; j++) {
                if (temp == a[j]){
                    b[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                a[k++] = temp;
                b[k - 1] = 1;
            }
        }
        for (int i = 0; i < k; i++) {
            if (b[i] % 2 != 0) {
                cout << a[i];
                break;
            }
        }
        cout << endl;
    }
}
        