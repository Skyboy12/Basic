#include <iostream>
#include <string>

using namespace std;

string ans[1005];
int ans_count;

string buffer[100000];
int head;
int tail;

bool check(const string& s) {
    int count_2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '2') {
            count_2++;
        }
    }
    return count_2 * 2 > s.length();
}

void gen() {
    buffer[tail++] = "1";
    buffer[tail++] = "2";

    while (ans_count < 1000 && head < tail) {
        string current = buffer[head++];

        if (check(current)) {
            ans[ans_count++] = current;
        }

        buffer[tail++] = current + '0';
        buffer[tail++] = current + '1';
        buffer[tail++] = current + '2';
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    head = 0;
    tail = 0;
    ans_count = 0;
    gen();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}