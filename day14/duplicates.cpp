#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int arr[10] = {2,66,33,2,1,2,4,66,49,87};
    cout << "the duplicate elements are : ";
    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(arr[i] == arr[j]){
                s.insert(arr[i]);
                break;
            }
        }
    }
    for(const auto& elem : s){
        cout << elem << " ";
    }
    return 0;
}   