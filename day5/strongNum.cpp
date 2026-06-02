#include <iostream>
using namespace std;
// strong number - numbrer whose sum of the factorial of all the digits is equal to the number itself/
int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}
bool strongNum(int num){
    int sum = 0, temp = num;
    while(num > 0){
        int rem = (num % 10);
        sum += factorial(rem);
        num = num/10;
    }
    if(sum == temp) return true;
    else return false;
}

int main(){
    int n = 145;
    cout << strongNum(n);
    return 0;
}