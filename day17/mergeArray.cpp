#include <iostream>
using namespace std;
int main() {
    int sz1 = 6, sz2 = 7;
    int arr1[] = {0,1,2,3,4,5};
    int arr2[] = {6,7,8,9,10,11,12};
    int sz = sz1 + sz2;
    int merged[sz];
    for(int i = 0; i < sz1; i++){
        merged[i] = arr1[i];
    }
    for(int i = 0; i < sz2; i++){
        merged[sz1 + i] = arr2[i];
    }

    for(int i = 0; i < sz; i++){
        cout << merged[i] << " ";
    }
    return 0;
}   