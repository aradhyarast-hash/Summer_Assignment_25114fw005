#include <iostream>
using namespace std;
int rotateArrayLeft(int arr[], int k, int i){

    int st1 = 0, end1 = i-k-1;
    while(st1 < end1){
        swap(arr[st1], arr[end1]);
        st1++;
        end1--;
    }
    int st2 = i-k+1, end2 = i-1;
    while(st2 < end2){
        swap(arr[st2], arr[end2]);
        st2++;
        end2--;
    }

    int start = 0, end = i-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return 0;
}
int main() {
    int n = 8;
    int arr[] = {3, 1, 4, 1, 4, 9, 6, 6};
    int k = 2;
    rotateArrayLeft(arr, k, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}