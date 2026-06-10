#include <iostream>
using namespace std;
//       1
//      121
//     12321
//    1234321
//   123454321
//  12345654321
int main() {
    int n = 6;
    for(int i = 0; i < n; i++){
        for(int m = i; m < n; m++){
            cout << " ";
        }
        for(int j = 1; j <= i+1; j++){
            cout << j;
        }

        for(int k = i; k >= 1; k--){
            cout << k;
        }
        cout << endl;
    }
    return 0;
}