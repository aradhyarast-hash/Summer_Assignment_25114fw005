#include <iostream>
using namespace std;
int binarytodecimal(long long binary){
    int decimal = 0;
    int mul = 1;
    while(binary > 0){
        int rem = binary % 10;
        decimal += rem * mul;
        mul = mul*2;
        binary = binary/10;
    }
    return decimal;
}
int main(){
    cout << binarytodecimal(1011);
    return 0;
}