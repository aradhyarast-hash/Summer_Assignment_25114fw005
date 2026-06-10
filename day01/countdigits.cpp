// program to count the number of digits in a number
#include <iostream>
using namespace std;
int main(){
    int count = 0;
    int n = 23455;
    while(n > 0){
        n = n / 10;
        count++;
    }
    cout << count;
    return 0;
}