#include <iostream>
using namespace std;

int main(){
    int a ;
    bool ans = true;
    cout << "enter any number to check if it is prime "<<endl;
    cin >> a;
    for(int i = 2; i <= a/2; i++){
        if((a % i) == 0) {
            ans = false;
        }
    }
    // 0 for non prime and 1 for prime number.
    if(ans == 0) cout << "the number is non-prime."<<endl;
    else cout << "the number is a prime number."<<endl;
    return 0;
}