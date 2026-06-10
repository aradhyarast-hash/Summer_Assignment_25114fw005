#include <iostream>
using namespace std;
int main() {
    int size = 5;
    int arr[5] = {1,2,3,5,6};
    int sum = 0, actSum = 0;
    for(int i = 1; i <= size+1; i++){
        sum += i;
    }

    for(int i = 0; i < size; i++){
        actSum += arr[i];
    }
    cout << "missing number is " << sum-actSum<< endl;
    return 0;
}