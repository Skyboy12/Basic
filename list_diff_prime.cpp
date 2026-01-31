#include <iostream>

using namespace std;

const int MAX_ALL = 1005;
bool is_prime[MAX_ALL];
int in_prime[MAX_ALL];
bool in_array_and_prime[MAX_ALL];

int sieve_of_eratosthenes() {
    for (int i = 2; i < MAX_ALL; ++i) {
        is_prime[i] = true;
    }
    int count = 0;
    for (int i = 2; i * i < MAX_ALL; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_ALL; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX_ALL; ++i) {
        if (is_prime[i]) {
            in_prime[count++] = i;
        }
    }
    return count;
}


int main() {
    int t;
    cin >> t;
    int count = sieve_of_eratosthenes();
    int max = MAX_ALL;
    /*for (int i = 0; i < count; ++i) {
        in_array_and_prime[in_prime[i]] = true;
        cout << in_prime[i] << " ";
    }*/
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (is_prime[x]) {
                in_array_and_prime[x] = true;
            }
        }
        for (int i = 0; i < count; ++i) {
            if (in_array_and_prime[in_prime[i]]) {
                cout << in_prime[i] << " ";
                max = in_prime[i];
                in_array_and_prime[in_prime[i]] = false;
            }
        }
        cout << endl;
    }
    return 0;
}