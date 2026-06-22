#include <iostream>
using namespace std;

int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
string removeSpace(string s){
    int len = stringLen(s);
    int i = 0;
    while(i < len){
        if(s[i] == ' '){
            s.erase(i, 1);
        }
        i++;
    }
    return s;
}
int main() {
    string str = "its day 22 of learning   ";
    cout << removeSpace(str);
    
    return 0;
}