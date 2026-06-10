#include <iostream>
using namespace std;
int main(){
    // 1 
    // 12 
    // 123 
    // 1234 
    // 12345
    for(int i = 1; i < 6; i++){
        int j = 1;
        while(j <= i){
            cout << j;
            j++;
        }
        cout << endl;
    }
    return 0;
}