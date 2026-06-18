#include <iostream>
using namespace std;

int main() {
    int size = 10;
    int arr[size] = {10,40,30,20,60,70,100,50,80,90};
    for(int i = 0; i < size-1; i++){
        int mini = i;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[i]){
                mini = j;
            }
        }
        swap(arr[i] , arr[mini]);
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}