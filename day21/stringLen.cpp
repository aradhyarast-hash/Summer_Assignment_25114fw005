#include <iostream>
using namespace std;

int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
int main() {
    string str = "Aradhya";
    cout << "the length of the string is : "<< stringLen(str);
    return 0;
}