#include <iostream>
using namespace std;
int main() {
    int n = 6;
    string array[n] = {"apple", "please", "hi", "banana", "cat", "a"};
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(array[j].size() > array[j+1].size()){
                swap(array[j], array[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << ", ";
    }
    return 0;
}