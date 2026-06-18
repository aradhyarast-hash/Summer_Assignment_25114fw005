#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        bool swapped = false;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }  
}

int main() {
    int sz = 10;
    int a[sz] = {2,643,42,67,67,34,6775,44,22,15};
    bubbleSort(a,sz);
    for(int i = 0 ; i < sz; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}