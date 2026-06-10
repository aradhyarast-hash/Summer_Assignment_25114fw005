#include <iostream>
using namespace std;

int sumOfDig(int number, int sum){
    if(number == 0) return sum;
    int rem = number % 10;
    sum += rem;
    return sumOfDig(number/10, sum);
}
int main(){
    cout << "the sum of digits is:" << sumOfDig(4475,0);
    return 0;
}