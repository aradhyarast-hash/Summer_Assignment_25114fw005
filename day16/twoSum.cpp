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

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    bool found = false;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == target){
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << endl;
                found = true;
            }
        }
    }

    if(!found){
        cout << "No pair found with sum " << target << endl;
    }

    return 0;
}