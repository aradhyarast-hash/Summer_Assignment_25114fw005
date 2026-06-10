#include <iostream>
using namespace std;
int countSetBit2(string binaryNum){
    int count = 0;
    for(int i = 0; i < binaryNum.size(); i++){
        if(binaryNum[i] == '1') count++;
    }
    return count;
}
int main(){
    cout << countSetBit2("101011101");
    return 0;
}