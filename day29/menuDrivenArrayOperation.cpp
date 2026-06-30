#include <iostream>
using namespace std;

void addElem(int arr[], int capacity, int &count, int elem){
    if(count >= capacity){
        cout << "no space in the array!" << endl;
        return;
    }
    arr[count] = elem;
    count++;
}

int popElem(int arr[], int &count){
    if(count == 0) return -1;  // or throw error
    count--;
    return arr[count];
}

void removeElem(int arr[], int &count, int index){
    if(index >= count || index < 0) return;
    for(int i = index; i < count - 1; i++){
        arr[i] = arr[i+1];
    }
    count--;
}

void sorting(int arr[], int count){
    for(int j = 0; j < count-1; j++){
        for(int k = 0; k < count-j-1; k++){   // fixed: was j-i-1
            if(arr[k] > arr[k+1]){
                swap(arr[k], arr[k+1]);
            }
        }
    }
    cout << "sorted array: " << endl;
    for(int a = 0; a < count; a++){
        cout << arr[a] << ", ";
    }
    cout << endl;
}

void reverseArr(int arr[], int count){
    for(int j = 0; j < count-1; j++){
        for(int k = 0; k < count-j-1; k++){
            if(arr[k] < arr[k+1]){
                swap(arr[k], arr[k+1]);
            }
        }
    }
    cout << "reversed array: " << endl;
    for(int a = 0; a < count; a++){
        cout << arr[a] << ", ";
    }
    cout << endl;
}

int main() {
    int capacity = 18;
    int array[capacity] = {23,45,22,1,78,2,1,55,8,84,2,225,6643,11,987,0};
    int count = 16;   // ← actual number of real elements you put in

    addElem(array, capacity, count, 90000000);
    sorting(array, count);
    reverseArr(array, count);

    return 0;
}