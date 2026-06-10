#include <iostream>

using namespace std;
string dectoBinary(int decimal){
    string s = "";
    while(decimal > 0){
        int rem = decimal%2;
        s = to_string(rem) + s; // adding to the front of the string
        decimal = decimal/2;
    }
    return s;
}
int main(){
    cout << dectoBinary(456);
    return 0;
}