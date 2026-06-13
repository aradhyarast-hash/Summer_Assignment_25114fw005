#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // input
    cout << "Enter " << n << " elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // count even and odd
    int even = 0, odd = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            even++;
        } else {
            odd++;
        }
    }

    cout << "Even count = " << even << endl;
    cout << "Odd count = " << odd << endl;

    return 0;
}