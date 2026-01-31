#include <iostream>
#include <algorithm>

using namespace std;

long long lucky_numbers[3000];
int lucky_count = 0;

void generate(long long current_num) {
    if (current_num > 10000000000LL) {
        return;
    }

    if (current_num > 0) {
        lucky_numbers[lucky_count++] = current_num;
    }

    generate(current_num * 10 + 4);
    generate(current_num * 10 + 7);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    generate(0);

    sort(lucky_numbers, lucky_numbers + lucky_count);

    long long total_sum = 0;
    long long current_pos = a;

    while (current_pos <= b) {
        long long* it = lower_bound(lucky_numbers, lucky_numbers + lucky_count, current_pos);
        
        long long next_lucky = *it;

        long long end_of_chunk = min(next_lucky, b);

        long long count = end_of_chunk - current_pos + 1;

        total_sum += count * next_lucky;

        current_pos = next_lucky + 1;
    }

    cout << total_sum << endl;

    return 0;
}