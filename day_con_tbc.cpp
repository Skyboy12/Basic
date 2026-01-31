#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    int count = 0;
    int count_max = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] == max) {
            count++;
        } else {
            if (count > count_max) {
                count_max = count;
            }
            count = 0;
        }
    }
    if (count > count_max) {
        count_max = count;
    }
    cout << count_max << endl;
    return 0;
}