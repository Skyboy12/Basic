#include <iostream>

using namespace std;

int array_print[20];

void print_array(int size) {
    for (int i = 0; i < size; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void try_solve(int n, int k, int index) {
    if (k == index) {
        print_array(k);
        return;
    }
    for (int i = n - k + index + 1; (i >= 1) && (i > array_print[index-1]); i--) {
        array_print[index] = i;
        try_solve(n, k, index + 1);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        try_solve(n, k, 0);
    }
}