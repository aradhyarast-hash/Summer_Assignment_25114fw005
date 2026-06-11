#include <iostream>
#include <climits>
using namespace std;

int findMax(int arr[], int size){
    int m = INT_MIN;
    for(int i = 0; i < size; i++){
        if(arr[i] > m){
            m = arr[i];
        }
    }
    return m;
}
int main() {
    int a[5] = {23,5,77,45,123};
    int sz = 5;
    cout << findMax(a, sz);
    return 0;
}