#include <iostream>

using namespace std;

bool is_fibonacci[10000];
void generate_fibonacci() {
    int a = 0, b = 1;
    is_fibonacci[a] = true;
    is_fibonacci[b] = true;

    for (int i = 2; i < 100; ++i) {
        int c = a + b;
        if (c >= 10000) break;
        is_fibonacci[c] = true;
        a = b;
        b = c;
    }
}

int array_print[34];
void print_array(int x) {
    for (int i = 0; i < x; ++i) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void solve_try(int n, int k, int index,int count, int total){
    if (k == count) {
        if (is_fibonacci[total]) {
            print_array(k);
        }
        return;
    }
    for (int i = index; i <= n; i++){
        array_print[count] = i;
        solve_try(n, k, i + 1, count + 1, total + i);
    }
}

void solve(int n, int k) {
    solve_try(n, k, 1, 0, 0);
}

int main(){
    generate_fibonacci();
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}