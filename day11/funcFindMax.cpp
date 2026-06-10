#include <iostream>
#include <vector>
#include <climits>  //required for the INT_MIN
using namespace std;
int findMax(vector<int> &arr){
    int n = arr.size(), m = INT_MIN;
    for(int i = 0 ; i < n; i++){
        m = max(arr[i], m);
    }
    return m;
}
int main() {
    vector<int> series = {2,76,2333,8765,34,466,333,2,3,5,987,10};
    cout << findMax(series);
    return 0;
}