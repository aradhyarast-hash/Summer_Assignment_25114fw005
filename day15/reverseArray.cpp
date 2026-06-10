#include <iostream>
using namespace std;
int main() {
    int n, elem;
    cout << "enter the size of array : "<< endl;
    cin >> n;
    int arr[n];
    cout << "enter the element: "<< endl;
    for(int i = 0; i < n; i++){
        cin >> elem;
        arr[i] = elem;
    }
    cout << "the array is: "<< endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int start = 0, end = n-1;
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    cout << "the reversed array is: "<< endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}