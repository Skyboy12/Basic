#include <iostream>

using namespace std;

int array_print[11];
bool used[11];
void print_array(int size, int m) {
    for (int i = 0; i < size; i++) {
        cout << array_print[i] << " ";
    }
    cout << m << endl;
}

void solve_try(int n, int size, int m){
    if (size == n - 1) {
        print_array(size, m);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            array_print[size] = i;
            solve_try(n, size + 1, m);
            used[i] = false;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        used[i] = false;
    }
    used[m] = true;
    solve_try(n, 0, m);
    return 0;
}