#include <iostream>
using namespace std;
int power(int number, int exponent){
    long long answer = 1;
    for(int i = 1; i <= exponent; i++){
        answer *= number;
    }
    return answer;
}
int main(){
    cout << power(2,5);
    return 0;
}