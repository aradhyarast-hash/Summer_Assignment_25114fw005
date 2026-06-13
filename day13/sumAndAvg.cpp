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

    // sum
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    // average
    double avg = (double)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;

    return 0;
}