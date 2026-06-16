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
    int result[n];
    int k = 0;

    for(int i = 0; i < n; i++){
        bool isDuplicate = false;
        for(int j = 0; j < k; j++){
            if(arr[i] == result[j]){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            result[k] = arr[i];
            k++;
        }
    }
    cout << "Array after removing duplicates: " << endl;
    for(int i = 0; i < k; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}