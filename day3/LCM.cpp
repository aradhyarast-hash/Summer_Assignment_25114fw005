#include <iostream>
using namespace std;

int gcd(int num1, int num2){
    int a = 0;
    int ans = 1;
    if(num1 > num2) a = num2;
    else a = num1;
    for(int i = 2; i <= a; i++){
        if(((num1 % i) == 0) && ((num2 % i) == 0)) {
            ans = i;
        }
    }
    return ans;
}

int lcm(int num1, int num2){
    int value = gcd(num1, num2);
    int answer = ((num1 * num2) / value);
    return answer;
}

int main(){
    int n1 = 28, n2 = 7;
    cout << "the lcm of the numbers is " << lcm(n1, n2);
    return 0;

}