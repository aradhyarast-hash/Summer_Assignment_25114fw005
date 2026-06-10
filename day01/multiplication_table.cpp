// multiplication table of a given number
#include <iostream>
using namespace std;

int multable(int num, int start, int till){
    if(start > till) return 0; 
    else{
        cout << num * start << endl;
        return multable(num, start+1, till);
    }
}
int main(){
    multable(2, 0, 10);
    return 0;
}