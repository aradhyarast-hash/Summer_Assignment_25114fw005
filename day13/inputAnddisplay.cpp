#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "enter the size of the array : " << endl;
    cin >> size;
    int arr[size];
    int a = 0;
    cout << "enter the " << size << " elements" << endl;
    for(int i = 0; i < size; i++){
        cin >> a;
        arr[i] = a;
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }
    return 0;
}