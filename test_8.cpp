#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    int En[n] = {0};
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        En[i] = En[i-1] + abs(arr[i] - arr[i-1]);
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; (j < k) && (i + j < n); j++){
            if (En[i + j] < En[i] + abs(arr[i + j] - arr[i])) {
                En[i + j] = En[i] + abs(arr[i + j] - arr[i]);
            }
        }
    }
    cout << En[n - 1];
    return 0;
}