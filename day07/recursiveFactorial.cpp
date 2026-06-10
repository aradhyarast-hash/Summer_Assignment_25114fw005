// to find the factorial of a number
#include <iostream>
using namespace std;
int factorial(int number){
    // base case
    if(number == 0) return 1;

    return (number * factorial(number-1));
}
int main(){
    int numb = 10;
    cout << factorial(numb);
    return 0;
}