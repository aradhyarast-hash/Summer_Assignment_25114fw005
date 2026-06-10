#include <iostream>
using namespace std;
int main() {
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    int target = 2 , freq = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] == target) freq++;
    }
    cout << "the frequency of the " << target << " is " << freq; 
    return 0;
}