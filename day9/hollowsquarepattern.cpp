#include <iostream>
using namespace std;
// *****

// *   *

// *   *

// *   *

// *****
int main() {

    for(int i = 0; i < 5; i++){
        int j = 0;
        while(j < 5){
            if((i != 0) && (i != 4) && (j != 0) && (j != 4)){
                cout << " ";
            }
            else cout << "*";
            j++;
        }
        cout << endl << endl;
    }
    return 0;
}