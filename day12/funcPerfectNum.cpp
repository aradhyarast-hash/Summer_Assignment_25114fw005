#include <iostream>
using namespace std;

// perfect number - sum of the factors of a number is equal to that number itself.
// ex - 6 -> 1,2,3 -> (1+2+3 = 6)

bool chkPerfectNum(int number){
    int sum = 0;
    for(int i = 1; i <= number/2; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    if(number == sum) return true;
    else return false;
}
int main() {
    int n = 5;
    cout << chkPerfectNum(n);
    return 0;
}