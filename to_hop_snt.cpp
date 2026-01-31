#include <iostream>

using namespace std;

bool is_prime[10000];
void sieve_of_eratosthenes() {
    for (int i = 2; i < 10000; ++i) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < 10000; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 10000; j += i) {
                is_prime[j] = false;
            }
        }
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
        if (is_prime[total]) {
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
    sieve_of_eratosthenes();
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}