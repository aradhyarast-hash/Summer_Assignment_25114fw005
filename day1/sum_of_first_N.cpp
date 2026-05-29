// sum of the first n natural numbers 
#include <iostream>
using namespace std;

int sumofN(int num){
    if(num == 0) return 0;
    return num + sumofN(num - 1);
}
int main(){

    int number = 15;
    cout << sumofN(number);
    return 0;

}