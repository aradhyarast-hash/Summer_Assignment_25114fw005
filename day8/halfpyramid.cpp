#include <iostream>
using namespace std;
//  Print half pyramid pattern
int main(){
    // *
    // **
    // ***
    // ****
    // *****
    for(int i = 0; i < 5; i++){
        int j = 0;
        while(j <= i){
            cout << '*';
            j++;
        }
        cout << endl;
    }
    //     *
    //    **
    //   ***
    //  ****
    // *****
    for(int i = 0; i < 5; i++){
        int j = 0;
        while(j < 5-i-1){
            cout << " ";
            j++;
        }
        while(j < 5){
            cout << '*';
            j++;
        }
        cout << endl;
    }

    return 0;
}