#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[] = {3, 0, 4, 1, 0, 9, 0, 6};
    int j = 0, i = 0;
    while(j <= i && i < n){
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }
    for(int k = 0; k < n; k++)
        cout << arr[k] << " ";
    return 0;
}