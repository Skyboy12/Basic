#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = -1;
vector<int> a(12);

void solve(int k, vector<vector<int>>& g) {
    if (k == 12) {
        long long max_s = 0;
        long long min_s = -1;

        for (int i = 0; i < 4; ++i) {
            long long s = 0;
            for (int x : g[i]) {
                s += x;
            }
            if (s > max_s) {
                max_s = s;
            }
            if (min_s == -1 || s < min_s) {
                min_s = s;
            }
        }

        long long d = max_s - min_s;
        if (ans == -1 || d < ans) {
            ans = d;
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (g[i].size() < 3) {
            g[i].push_back(a[k]);
            solve(k + 1, g);
            g[i].pop_back();
            if (g[i].empty()) {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 12; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<vector<int>> g(4);
    solve(0, g);

    cout << ans << endl;

    return 0;
}