#include <iostream>
using namespace std;
int main() {
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    // sum of entire array
    int sum = 0;
    double avg = 0.0;
    for(int i = 0; i < 10; i++){
        sum += arr[i];
    }
    // average of the array elements
    avg = sum/10;
    cout << "the sum of the array is " << sum << endl;
    cout << "the average of the array is " << avg << endl;
    return 0;
}