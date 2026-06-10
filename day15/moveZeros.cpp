#include <iostream>
using namespace std;
int main() {
    int arr[11] = {0,1,3,0,5,0,9,4,0,2,5};
    cout << "the array is: "<< endl;
    for(int i = 0; i < 11; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int p1 = 0, p2 = 0;
    while(p1 <= p2 && p2 < 11){
        if(arr[p2] != 0){
            swap(arr[p1] , arr[p2]); 
            p1++;
            p2++;   
        }
        else p2++;
    }
    
    cout << "the new array is: "<< endl;
    for(int i = 0; i < 11; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}