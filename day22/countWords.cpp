#include <iostream>
using namespace std;
int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
int countWords(string st){
    int cnt = 1;
    int len = stringLen(st);
    int i = 0;
    while(i != len){
        if(st[i] == ' '){
            cnt++;
        }
        i++;
    }
    return cnt;
}
int main() {
    string st = "This is my day 22 assignment";
    cout << "the number of words are "<< countWords(st);
    return 0;
}