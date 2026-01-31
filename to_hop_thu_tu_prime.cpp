#include <iostream>

using namespace std;

int array_print[21];

void print_array(int n) {
    for (int i = 0; i < n; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

const int max_prime = 100000;
bool is_prime[max_prime];

void sieve() {
    for (int i = 2; i < max_prime; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < max_prime; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < max_prime; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int count = 0;

void generate(int n, int k, int index) {
    if (k == index) {
        count++;
        if (is_prime[count]){
            cout << count << ": ";
            print_array(k);
        }
        return;
    }
    for (int i = array_print[index - 1] + 1; i <= n; i++) {
        array_print[index] = i;
        generate(n, k, index + 1);
    }
}

int main(){
    int n,k;
    sieve();
    cin >> n >> k;
    generate(n, k, 0);
    return 0;
}