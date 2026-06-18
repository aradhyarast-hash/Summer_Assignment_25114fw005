#include <iostream>
using namespace std;

void descendSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int maxi = i;
        for(int j = i; j < size; j++){
            if(arr[j] > arr[maxi]){
                maxi = j;
            }
        }
        swap(arr[i], arr[maxi]);
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int size = 10;
    int arr[size] = {10,40,30,20,60,70,100,50,80,90};
    descendSort(arr, size);
    return 0;
}