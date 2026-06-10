#include <iostream>
using namespace std;
int countSetBit(long long binaryNum){
    int i = 0, count = 0;
    while(binaryNum > 0){
        if(binaryNum & 1){
            count++;
        }
        binaryNum = binaryNum >> 1;
    }
    return count;
}
int main(){
    cout << countSetBit(0b101011101);
    return 0;
}