#include <iostream>

using namespace std;

int colored[6005][6005] = {0};
int sum_colored[6005][6005] = {0};

int a, b, c, d, e;

int main() {
    cin >> a >> b >> c >> d >> e;
    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;
        colored[x][y] = 1;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            sum_colored[i][j] = sum_colored[i - 1][j] + sum_colored[i][j - 1] - sum_colored[i - 1][j - 1] + colored[i][j];
        }
    }
    int max_length = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int length = max_length - 1 + d; length + i <= a && length + j <= b; length += d) {
                int x1 = i, y1 = j;
                int x2 = i + length, y2 = j + length;
                int total_colored = sum_colored[x2][y2] - sum_colored[x1 - 1][y2] - sum_colored[x2][y1 - 1] + sum_colored[x1 - 1][y1 - 1];
                if (total_colored <= e) {
                    max_length = max(max_length, length + 1);
                } else {
                    break;
                }
            }
        }
    }
    cout << max_length << endl;
    return 0;
}
