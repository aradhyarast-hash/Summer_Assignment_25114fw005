// to reverse the number
#include <iostream>
using namespace std;
int revNum(int number){
    int rev = 0;
    while(number > 0){
        int rem = number%10;
        rev = rev*10 + rem;
        number = number/10;
    }
    return rev;
}
int main(){
    int num = 2566;
    cout << revNum(num);
    return 0;
}