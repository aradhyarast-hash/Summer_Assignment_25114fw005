#include <iostream>
using namespace std;
int main() {
    int n = 5;
    char c = 'A';
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << " ";
        }
        for(int k = 0; k <= i; k++){
            cout << (char)('A' + k);
            c++;
        }
        for(int m = i-1; m >= 0; m--){
            cout << (char)('A' + m);
        }
        
        cout << endl;
    }
    return 0;
}
