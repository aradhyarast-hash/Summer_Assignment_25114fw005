#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int arr[5] = {1,1,4,4,5};
    int i = 0;
    for(int j = 1; j <  5; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    int newsize = i+1;
    cout << "new array: " << endl;
    for(int i = 0; i < newsize; i++){
        cout << arr[i] << " ";
    }
    return 0;
}