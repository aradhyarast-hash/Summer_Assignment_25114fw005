#include <iostream>
using namespace std;
int main() {
    int n = 5, target = 5;
    int arr[n] = {3,6,50,7,12};
    int i = 0;
    for(i = 0; i < n; i++){
        if(target == arr[i]){
            cout << i<< endl;
            break;
        }
    }
    if(i == n) cout << "element not found" << endl;
    return 0;
}