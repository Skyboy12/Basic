#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        bool check = true;
        for (int i = 0; i < input.size(); i++){
            if(!(input[i] == '1' || input[i] == '0' || input[i] == '2')){
                check = false;
                break;
            }
        }
        if (check){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}