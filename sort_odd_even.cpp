#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int oddCount = 0, evenCount = 0;
    int oddarr[n], evenarr[n];
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp % 2;
        if (arr[i] == 0) {
            evenarr[evenCount++] = temp;
        } else {
            oddarr[oddCount++] = temp;
        }
    }
    sort(oddarr, oddarr + oddCount);
    sort(evenarr, evenarr + evenCount);
    evenCount = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0) {
            cout << evenarr[evenCount++] << " ";
        } else {
            cout << oddarr[--oddCount] << " ";
        }
    }

    return 0;
}