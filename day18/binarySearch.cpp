#include <iostream>
using namespace std;

// binary search applied on the sorted array
int searchBinary(int arr[], int size, int target){
    
    // binary search
    int s = 0, e = size-1;
    while(s < e){
        int mid = s + (e - s)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
    }
}
int main() {
    int size = 10;
    int arr[size] = {10,20,30,40,50,60,70,80,90,100};
    int target = 70;
    cout << searchBinary(arr, size,target) << endl;
    return 0;
}