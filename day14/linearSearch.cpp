#include <iostream>
using namespace std;
int main() {
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    int target = 4, ans = -1;
    for(int i = 0; i < 10; i++){
        if(arr[i] == target) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}