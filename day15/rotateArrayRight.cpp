#include <iostream>
using namespace std;
int main() {
    int arr[5] = {1,2,3,4,5};
    int endposition = 2;
    // ans array = {4,5,1,2,3}


    cout << "the array is: "<< endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int start1 = 0, end1 = 5-endposition-1;
    while(start1 < end1){
        swap(arr[start1], arr[end1]);
        start1++;
        end1--;
    }

    int start2 = 5-endposition, end2 = 5-1;
    while(start2 < end2){
        swap(arr[start2], arr[end2]);
        start2++;
        end2--;
    }

    int start = 0, end = 5-1;
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