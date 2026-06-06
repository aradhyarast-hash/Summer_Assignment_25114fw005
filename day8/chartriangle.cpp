#include <iostream>
using namespace std;
// A
// AB
// ABC
// ABCD
// ABCDE
int main(){
    for(char i = 'A'; i <= 'E'; i++){
        char c = 'A';
        while(c <= i){
            cout << c;
            c++;
        }
        cout << endl;
    }
    return 0;
}