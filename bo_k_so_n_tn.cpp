#include <iostream>
#include <vector>

using namespace std;

void flip_flop(int n, vector<int>& arr , int k) {
    for (int i = n - 1; i >= 0 ; i--) {
        if (arr[i] < k){
            arr[i] += 1;
            break;
        } else {
            arr[i] = arr[i-1] + 1;   
        }
        
    }

}