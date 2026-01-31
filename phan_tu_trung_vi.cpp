#include <bits/stdc++.h>

using namespace std;

void push_sort(vector<int>& queue, int value) {
    auto it = lower_bound(queue.begin(), queue.end(), value);
    queue.insert(it, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> queue;
    int action_times;
    cin >> action_times;
    while (action_times--){
        string action;
        cin >> action;
        if (action == "add" || action == "del"){
            int action_value;
            cin >> action_value;
            if (action == "add"){
                push_sort(queue, action_value);
            }
            else if (action == "del"){
                auto it = lower_bound(queue.begin(), queue.end(), action_value);
                if (it != queue.end() && *it == action_value) {
                    queue.erase(it);
                }
            }
        }
        else if (action == "print"){
            cout << queue.at(((queue.size() + 1) / 2) - 1) << endl;
        }
    }
}