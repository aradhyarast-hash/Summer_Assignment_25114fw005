#include <iostream>
using namespace std;
bool chkperfect(int num){
    int prod = 1;
    for(int i = 2; i < num; i++){
        if((num % i) == 0) prod *= i;
    }
    // 1 for true and 0 for false
    if(prod == num) return true;
    else return false; 
}
int main(){
    cout << chkperfect(10);
    return 0;
}