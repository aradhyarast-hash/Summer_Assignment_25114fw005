#include <iostream>
using namespace std;

bool checkPerfect(int number){
    int prod = 1;
    for(int i = 1; i <= number/2; i++){
        if((number % i) == 0) prod *= i;
    }
    if(prod == number) return true;
    else return false;
}
int main() {
    cout << checkPerfect(6);
    return 0;
}