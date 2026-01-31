#include <iostream>

using namespace std;

// Hàm phân tích thừa số nguyên tố của p, lưu vào 2 mảng
void factorize(int p, int primes[], int exponents[], int &count) {
    count = 0;
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0) {
            primes[count] = i;
            exponents[count] = 0;
            while (p % i == 0) {
                exponents[count]++;
                p /= i;
            }
            count++;
        }
    }
    if (p > 1) {
        primes[count] = p;
        exponents[count] = 1;
        count++;
    }
}

// Đếm số lần một số nguyên tố xuất hiện trong n!
int count_in_factorial(int n, int prime) {
    int count = 0;
    while (n > 0) {
        n /= prime;
        count += n;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;

        int primes[32], exponents[32], num_factors;
        factorize(p, primes, exponents, num_factors);

        int result = 1000000000; // Một số rất lớn
        for (int i = 0; i < num_factors; ++i) {
            int cnt = count_in_factorial(n, primes[i]);
            int k = cnt / exponents[i];
            if (k < result) {
                result = k;
            }
        }

        cout << result << endl;
    }

    return 0;
}
