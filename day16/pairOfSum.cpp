#include <iostream>
#include <vector>
using namespace std;

// two sum problem
int main() {
    int sum = 0, target = 9;
    vector<int> pair;
    int arr[5] = {1,4,3,4,5};
    for(int i = 0; i < 4; i++){
        int j = i+1;
        int a = 0;
        while(j < 5){
            sum = arr[i] + arr[j];
            if(sum == target){
                pair.push_back(arr[i]);
                pair.push_back(arr[j]);
                break;
                a = 1;
            }
            j++;

        }
        if(a == 1) break;
    }
    cout << pair[0] <<" , " << pair[1]<< endl;
    return 0;
}