#include <iostream>

using namespace std;

int array_print[11];
bool used[11];
int count = 1;
void print_array(int size) {
    cout << count++ << ": ";
    for (int i = 0; i < size; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void solve_try(int n, int size){
    if (size == n) {
        print_array(size);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            array_print[size] = i;
            solve_try(n, size + 1);
            used[i] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        used[i] = false;
    }
    solve_try(n, 0);
    return 0;
}