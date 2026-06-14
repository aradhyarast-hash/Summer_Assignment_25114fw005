#include <iostream>
using namespace std;
int main() {
    int n = 5, target = 50, freq = 0;
    int arr[n] = {3,6,50,50,12};
    for(int i = 0;i < n; i++){
        if(arr[i] == target){
            freq++;
        }
    }
    cout << "the frequency of "<< target << " is " << freq;
    return 0;
}