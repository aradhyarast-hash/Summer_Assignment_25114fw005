#include <iostream>
using namespace std;

int stringLen(string s){
    int a = 0;
    while(s[a] != '\0'){
        a++;
    }
    return a;
}
int countConsonent(string s){
    int cnt = 0;
    int l = stringLen(s);
    for(int i = 0; i < l; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'I' || s[i] == 'U'){
            continue;
        }
        else cnt++;
    }
    return cnt;
}
int countVowel(string s){
    int cnt = 0;
    int l = stringLen(s);
    for(int i = 0; i < l; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'I' || s[i] == 'U'){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string str = "Aradhya";
    cout << "number of vowel is "<< countVowel(str)<< endl;
    cout << "number of consonent is "<< countConsonent(str);
    return 0;
}