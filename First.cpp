#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string array_print[10];

bool is_used[10];

void print_array(int size) {
    for (int i = 0; i < size; i++) {
        cout << array_print[i] << " ";
    }
    cout << endl;
}

void generate_array(int index, int size, string element[]){
    if (index == size) {
        print_array(size);
        return;
    }
    
    for (int i = 0; i < size; i++) {
        if (!is_used[i]) {
            is_used[i] = true;
            array_print[index] = element[i];
            generate_array(index + 1, size, element);
            is_used[i] = false;
        }
    }
}

int main() {
    int size;
    cin >> size;
    string element[size];
    cin.ignore();
    for (int i = 0; i < size; i++) {
        cin >> element[i];
    }
    sort(element, element + size);
    cin.ignore();
    string special;
    cin >> special;
    array_print[0] = special;
    int special_index = 0;
    for (int i = 0; i < size; i++) {
        if (element[i] == special) {
            special_index = i;
            break;
        }
    }
    is_used[special_index] = true;
    generate_array(1, size, element);
    return 0;
}