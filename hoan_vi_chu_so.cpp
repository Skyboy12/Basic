#include <iostream>
#include <algorithm>

using namespace std;

int array_print[10];
bool used[10];

void print_array(int n) {
    int number = 0;
    for (int i = 0; i < n; i++) {
        number = number * 10 + array_print[i];
    }
    cout << number << endl;
}

void generate(int n, int pos, int numberchar[]){
    if (pos == n) {
        print_array(n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            array_print[pos] = numberchar[i];
            generate(n, pos + 1, numberchar);
            used[i] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int number;
        cin >> number;
        int numberchar[10];
        int number_length = 0;
        while (number > 0) {
            numberchar[number_length++] = number % 10;
            number /= 10;
        }
        for (int i = 0; i < 10; i++) {
            used[i] = false;
        }
        sort(numberchar, numberchar + number_length);
        generate(number_length, 0, numberchar);
    }
    return 0;
}