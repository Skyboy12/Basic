#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        pq.push(val);
    }

    long long total_cost = 0;

    while (pq.size() > 1) {
        int group_size = min((int)pq.size(), k);
        
        long long current_sum = 0;
        long long min_in_group = -1, max_in_group = -1;

        for (int i = 0; i < group_size; ++i) {
            long long current_val = pq.top();
            pq.pop();
            
            if (i == 0) {
                min_in_group = current_val;
            }
            if (i == group_size - 1) {
                max_in_group = current_val;
            }
            
            current_sum += current_val;
        }

        total_cost += (max_in_group - min_in_group);
        pq.push(current_sum);
    }

    cout << pq.top() << endl;
    cout << total_cost << endl;

    return 0;
}