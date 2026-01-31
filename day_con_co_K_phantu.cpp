#include <iostream>
#include <algorithm>

using namespace std;
int array_print[105];
void printArray(int size) {
    for (int i = 0; i < size; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void try_and_print(int array[], int n, int k, int index, int current_size) {
    if (current_size == k) {
        sort(array_print, array_print + k);
        printArray(k);
        return;
    }
    if (index >= n) {
        return;
    }
    for (int i = index; i < n; i++) {
        array_print[current_size] = array[i];
        try_and_print(array, n, k, i + 1, current_size + 1);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    try_and_print(a, n, k, 0, 0);
    return 0;
}
