#include <iostream>
using namespace std;
int findfactorial(int num){
    if(num < 0) return -1;
    if((num == 0) && (num == 1)) return 1;

    int prod = 1;
    for(int i = 1; i <= num; i++){
        prod = prod*i;
    }
    return prod;
}
int main() {
    cout << findfactorial(6);
    return 0;
}