#include <bits/stdc++.h>

using namespace std;

string ans[10005];

void generate(){
    ans[0] = "4"; ans[1] = "5";
    int count = 2;
    int begin = 0, end = 1;
    for (int numchar = 2; numchar <= 12; numchar++){
        for (int i = begin; i <= end; i++){
            for (char c = '4'; c <= '5'; c++){
                ans[count++] = ans[i] + c;
                if (count > 10000) return;
            }
        }
        begin = end + 1;
        end = count - 1;
    }
}

void printans(int n){
    string needprint = ans[n];
    cout << needprint;
    reverse(needprint.begin(), needprint.end());
    cout << needprint << " ";
}

int main(){
    generate();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            printans(i);
        }
        cout << "\n";
    }
    return 0;
}