#include <iostream>
#include <cmath>
using namespace std;

bool armstrong(int number){
    int n =  number, sum = 0;
    int count = 1;
    while(n != 0){
        if(n / 10) count++;
        n = (n / 10);
    }
    n = number;
    while(n != 0){
        int rem = (n % 10);
        sum += pow(rem, count);
        n = (n / 10);
    }
    if((sum+1) == number) return true;
    else return false;
}
int main(){
    int number = 153;
    cout << armstrong(number);
    return 0;
}