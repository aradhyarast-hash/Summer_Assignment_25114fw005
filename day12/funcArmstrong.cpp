#include <iostream>
#include <cmath>
using namespace std;

bool chkArmstrong(int num){
    // number of digits in the number
    int n = num, cnt = 0;
    while(n > 0){
        cnt++;
        n = n / 10;
    }
    n = num;
    int sum = 0;
    while(n > 0){
        int rem = n % 10;
        sum += round(pow(rem,cnt));
        n = n / 10;
    }
    if(sum == num) return true;
    else return false;
}
int main() {

    int a = 153;
    cout << chkArmstrong(a);
    return 0;
}