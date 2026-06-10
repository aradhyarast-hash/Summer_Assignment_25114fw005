#include <iostream>
using namespace std;
// A
// BB
// CCC
// DDDD
// EEEEE
int main() {
    char c = 'A';
    for(int i = 0; i < 5; i++){
        int count = 0;
        while(count <= i){
            cout << c;
            count++;
        }
        c++;
        cout << endl;
    }
    return 0;
}