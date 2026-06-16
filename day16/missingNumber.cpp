#include <iostream>
using namespace std;
int main() {
    int n = 5, sum = 0, add = 0;
    int arr[] = {1,2,3,5,6};
    for(int i = 1; i <= n+1; i++){
        sum += i;
    }
    for(int j = 0; j < n; j++){
        add += arr[j];
    }
    cout << " missing number is "<< sum-add<< endl;
    return 0;
}