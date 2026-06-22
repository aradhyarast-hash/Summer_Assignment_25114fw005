#include <iostream>
using namespace std;
int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
int countFreq(string s, char a){
    int len = stringLen(s);
    int cnt = 0;
    while(len >= 0){
        if(s[len] == a){
            cnt++;
        }
        len--;
    }
    return cnt;
}
int main() {

    string s = "aradhya";
    cout << countFreq(s,'a');
    return 0;
}