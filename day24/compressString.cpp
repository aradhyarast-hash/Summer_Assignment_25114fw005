#include <iostream>
#include <unordered_map>
using namespace std;

string compressStr(string s){
    int prev = 0, count = 0;
    string newstr;
    for(int i = 0; i < s.length(); i++){
        if(s[prev] == s[i]){
            count++;
        }
        else {
            newstr += s[prev];
            newstr += to_string(count);
            prev = i;
            count = 1;
        }
    }

    newstr += s[prev];
    newstr += to_string(count);

    return newstr;
}

int main() {
    string str = "abbbbsssaaa   qqqqqqa";
    cout << compressStr(str);
    return 0;
}