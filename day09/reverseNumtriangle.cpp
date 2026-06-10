#include <iostream>
using namespace std;
// 12345
// 1234
// 123
// 12
// 1
int main() {
    for(int i = 0; i < 5; i++){
        int j = 1;
        while(j <= (5-i)){
            cout << j;
            j++;
        }
        cout << endl;
    }
    return 0;
}
