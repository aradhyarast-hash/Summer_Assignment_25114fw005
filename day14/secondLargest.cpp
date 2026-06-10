#include <iostream>
#include <climits>
using namespace std;

int main() {
    int largest = INT_MIN;
    int secondlargest = INT_MIN;
    int arr[10] = {2,68,33,2,1,2,4,66,49,87};
    for(int i = 0; i < 10; i++){
        if(arr[i] > largest){
            secondlargest = largest;
            largest = arr[i];
        }
    }
    cout << "the second largest element of the array is "<< secondlargest;
    return 0;
}