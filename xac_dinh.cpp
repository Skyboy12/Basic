#include <iostream>
#include <cmath>

using namespace std;

long long getValue(long long x, long long y) {
    long long d = x + y - 1;
    long long prev_diag_last_val = (d - 1) * d / 2;
    return prev_diag_last_val + y;
}

void getCoords(long long z) {
    long long d = static_cast<long long>(ceil((-1.0 + sqrt(1.0 + 8.0 * z)) / 2.0));
    long long prev_diag_last_val = (d - 1) * d / 2;
    long long y = z - prev_diag_last_val;
    long long x = d - y + 1;
    cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    cin >> x >> y;
    cout << getValue(x, y) << endl;

    long long z;
    cin >> z;
    getCoords(z);

    return 0;
}
