#include <iostream>
using namespace std;

int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
bool chkPalin(string s){
    int len = stringLen(s)-1;
    string str;
    while(len >= 0){
        str.push_back(s[len]);
        len--;
    }
    if(str == s){
        return true;
    }
    else return false;
}
int main() {
    string a = "mom";
    cout << chkPalin(a);
    return 0;
}