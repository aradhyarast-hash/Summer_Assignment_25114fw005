#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxFreq = 0;
    int maxElem = arr[0];

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > maxFreq){
            maxFreq = count;
            maxElem = arr[i];
        }
    }

    cout << "Maximum frequency element = " << maxElem << endl;
    cout << "Frequency = " << maxFreq << endl;

    return 0;
}