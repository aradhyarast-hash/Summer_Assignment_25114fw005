#include <iostream>
using namespace std;

bool checkPrime(int num){
    bool ans = true;
    for(int i = 2; i*i <= num; i++){
        if((num % i) == 0) {
            ans = false;
            break;
        }
    }
    return ans;
}
int main() {
    cout << checkPrime(70);
    return 0;
}