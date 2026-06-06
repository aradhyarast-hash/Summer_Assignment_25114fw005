#include <iostream>
using namespace std;
// *****
// ****
// ***
// **
// *
int main() {

    for(int i = 0; i < 5; i++){
        int j = 5-i;
        while(j > 0){
            cout << "*";
            j--;
        }
        cout << endl;
    }
    return 0;
}