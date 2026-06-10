#include <iostream>
using namespace std;
// 1
// 22
// 333
// 4444
// 55555
int main(){
    int n = 1;
    for(int i = 1; i <= 5; i++){
        int freq = i;
        while(freq){
            cout << n;
            freq--;
        }
        n++;
        cout << endl;
    }
    return 0;
}