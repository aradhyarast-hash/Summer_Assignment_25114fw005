#include <iostream>
using namespace std;
int main() {
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    int even = 0, odd = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > 0){
            if(arr[i] % 2 == 0) even++;
            else odd++; 
        }
        else {
            cout << "array consists of negative elements." << endl;
            exit(0);
        }
    }
    cout << "the even number of elements are " << even << endl;
    cout << "the odd number of elements are " << odd << endl;
    return 0;
}