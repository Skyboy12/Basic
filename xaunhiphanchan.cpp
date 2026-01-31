#include <iostream>

using namespace std;

int array_print[16];
int bit_true_count;

void print_array(int n) {
    for (int i = 0; i < n; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void solve(int n, int index){
    if (index == n) {
        if (bit_true_count % 2 == 0) {
            print_array(n);
        }
        return;
    }
    for (int i = 0; i < 2; i++){
        array_print[index] = i;
        bit_true_count += i;
        solve(n, index + 1);
        bit_true_count -= i;
    }
}

int main(){
    int n;
    cin >> n;
    solve(n, 0);
    return 0;
}