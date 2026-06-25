#include <iostream>
using namespace std;

int main() {
    int size1 = 5, size2 = 11;
    int array1[size1] = {1,3,6,9,12};
    int array2[size2] = {2,4,6,7,10,14,18,19,20,22,23};
    int len1 = 0, len2 = 0;
    int arrayAns[size1 + size2];
    int index = 0;
    while(len1 < size1 && len2 < size2 && index < size1+size2){
        if(array1[len1] <= array2[len2]){
            arrayAns[index] = array1[len1];
            len1++;
        }
        else{
            arrayAns[index] = array2[len2];
            len2++;
        }
        index++;
    }

    while(len1 < size1){
        arrayAns[index] = array1[len1];
        len1++;
        index++;
    }

    while(len2 < size2){
        arrayAns[index] = array2[len2];
        len2++;
        index++;
    }

    for(int i = 0; i < size1+size2; i++){
        cout << arrayAns[i]<< " ";
    }
    return 0;
}