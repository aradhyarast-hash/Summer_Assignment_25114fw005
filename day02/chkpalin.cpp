#include <iostream>
using namespace std;

int main(){
    int num = 3434;
    int newnum = 0;
    int number = num;
    while(num > 0){
        int rem = num % 10;
        newnum = newnum*10 + rem;
        num = num / 10;
    }

    if(newnum == number) {
    cout <<"palindrome";
    }
    else cout << "not a palindrome";
    return 0;
}