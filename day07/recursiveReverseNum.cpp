#include <iostream>
using namespace std;
// reverse a number;
int reverseNum(int number, int num){
    if(number == 0) return num;
    int rem = number % 10;
    num = num*10 + rem;
    return reverseNum(number/10, num);
}
int main(){
    cout << reverseNum(3456789, 0);
    return 0;
}