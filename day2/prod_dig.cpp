// finding the product of the digit
#include <iostream>
using namespace std;
int prod_dig(int number){
    int prod = 1;
    while(number > 0){
        int rem = number % 10;
        prod = prod * rem;
        number = number/10;
    }
    return prod;
}
int main(){
    int num = 4423;
    cout << prod_dig(num);
    return 0;
}