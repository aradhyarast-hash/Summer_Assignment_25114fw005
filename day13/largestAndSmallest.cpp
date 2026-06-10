#include <iostream>
#include <climits>
using namespace std;

int main() {
    int mini = INT_MAX, maxi = INT_MIN;
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    for(int i = 0; i < 10; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    cout << "the maximum element in the array is : "<< maxi << endl;
    cout << "the minimum element in the array is : "<< mini << endl;
    return 0;
}