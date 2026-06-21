#include <iostream>
using namespace std;

int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
string reverseStr(string s){
    string st;
    int num = stringLen(s)-1;
    while(num >= 0){
        st.push_back(s[num]);
        num--;
    }
    return st;
}
int main() {
    string str = "Aradhya";
    string s = reverseStr(str);
    cout << s;
    return 0;
}