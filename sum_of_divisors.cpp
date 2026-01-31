#include <iostream>
#include <vector>

using namespace std;

long long sum_of_divisors(int n) {
    if (n < 2) return n;
    long long total_sum = 1;

    
    if (n % 2 == 0) {
        long long term_sum = 3;
        n /= 2;
        while (n % 2 == 0) {
            term_sum = (term_sum * 2) + 1;
            n /= 2;
        }
        total_sum *= term_sum;
    }
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            long long term_sum = 1 + i;
            n /= i;
            while (n % i == 0) {
                term_sum = (term_sum * i) + 1;
                n /= i;
            }
            total_sum *= term_sum;
        }
    }

    if (n > 1) {
        total_sum *= (1 + n);
    }
    return total_sum;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<bool> is_prime(b + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= b; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }

    long long ans = 0;
    for (int i = a; i <= b; ++i) {
        if (is_prime[i]) continue;
        long long sum = sum_of_divisors(i) - i;

        if (sum > i)
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}