#include <iostream>

using namespace std;

const int limit = 1e6 + 5;

int dlist[limit];

void generate(){
    for (int i = 0; i < limit; i++) {
        dlist[i] = 0;
    }
    for (int i = 1; i < limit; i++){
        for (int j = i; j < limit; j+=i){
            dlist[j]++;
        }
    }
}

int main(){
    generate();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << dlist[n] << endl;
    }
    return 0;
}