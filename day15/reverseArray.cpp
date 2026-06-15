#include <iostream>
using namespace std;
int main() {
    int n = 8;
    int arr[] = {3, 1, 4, 1, 4, 9, 6, 6};
    int st = 0, end = n-1;
    while(st < end){
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
    return 0;
}