#include <iostream>
using namespace std;
int main() {
    int arr[5] = {1,2,3,4,5};
    int index = 2;
    cout << "the array is: "<< endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int start1 = 0, end1 = index-1;
    while(start1 < end1){
        swap(arr[start1], arr[end1]);
        start1++;
        end1--;
    }

    int start2 = index, end2 = 4;
    while(start2 < end2){
        swap(arr[start2], arr[end2]);
        start2++;
        end2--;
    }
    int start = 0, end = 4;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    cout << "the new array is: "<< endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}