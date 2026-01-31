#include <iostream>

using namespace std;

bool is_prime[100005];

void sieve() {
    for (int i = 2; i < 100005; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < 100005; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100005; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int max_prime_factor[100005];

void sieve_max_prime_factor() {
    for (int i = 2; i < 100005; ++i) {
        if (is_prime[i]) {
            for (int j = i; j < 100005; j += i) {
                max_prime_factor[j] = i;
            }
        }
    }
}

int main(){
    sieve();
    sieve_max_prime_factor();
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        int total = 0;
        for (int i = L; i <= R; ++i) {
            total += max_prime_factor[i];
        }
        cout << total << endl;
    }
    return 0;
}