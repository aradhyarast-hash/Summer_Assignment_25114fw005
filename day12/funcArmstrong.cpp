#include <iostream>
#include <cmath>
using namespace std;
bool checkarmstrong(int number){
    int sum = 0, prod = 1, count = 0;
    int temp = number;
    while(temp > 0){
        temp = temp/10;
        count++;
    }
    temp = number;
    while(temp > 0){
        int rem = temp % 10;
        sum += round(pow(rem, count));
        temp = temp/10;
    }
    return (sum == number);
}
int main() {
    cout << checkarmstrong(153);

    return 0;
}