#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 10;
    string array[n] = {"dishant", "archita","aaradhya", "ishika", "hemlata","arpit", "mehak", "nishant", "rita", "jeetu"};
    // sort(array, array + n);
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << array[i] << ", ";
    }
    return 0;
}