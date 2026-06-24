#include <iostream>
#include <unordered_map>
using namespace std;

string removeDupicate(string str){
    int size = str.size();
    string newstr = "";
    unordered_map<char, int> duplicate;
    for(int i = 0; i < size; i++){
        if(duplicate[str[i]] == 0){
            duplicate[str[i]]++;
            newstr += str[i];
        }
    }
    return newstr;
}
int main() {
    string s = "aaabbbbbssssss";
    cout << removeDupicate(s);
    return 0;
}