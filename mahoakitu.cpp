#include <iostream>
#include <string>

using namespace std;

main(){
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int i = 0;
        int step;
        string result = "";
        while (i < s.length()) {
            step = i;
            while (step < s.length() && s[step] == s[i]) {
                step++;
            }
            result += to_string(step - i) + s[i];
            i = step;
        } 
        cout << result;
        cout << endl;
    }
}