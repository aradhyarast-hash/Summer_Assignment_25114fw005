#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int arr[12] = {1,2,3,4,5,5,4,4,3,4,1,4};
    unordered_map<int, int> freq;
    for(int i = 0; i < 12; i++){
        freq[arr[i]]++;
    }
    int f = 0;
    int ans = arr[0];
    for(auto a : freq){
        if(a.second > f){
            f = a.second;
            ans = a.first;
        }
    }
    cout << "maximum frequency element in array is " << ans<< endl;
    return 0;
}