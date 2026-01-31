#include <iostream>
#include <string>

using namespace std;

int compare(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size() ? -1 : 1;
    }
    return a < b ? -1 : (a > b ? 1 : 0);
}

void quickSort(string arr[], int left, int right) {
    if (left >= right) return;
    string pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (compare(arr[i], pivot) < 0) i++;
        while (compare(arr[j], pivot) > 0) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main(){
    int n;
    cin >> n;
    string arr[505];
    string input;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        int j = 0;
        int len = input.size();
        while (j < len) {
            if (!(input[j] - '0' > 0 && input[j] - '0' <= 9)) {
                j++;
                continue;
            } 
            string temp;
            int count = 0;
            while (j + count < len && !(input[j + count] - '0' < 0 || input[ j +count] - '0' > 9)) {
                count++;
            }
            temp = input.substr(j, count);
            arr[k++] = temp;
            j += count;
        }
    }
    quickSort(arr, 0, k - 1);
    for (int i = 0; i < k; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}