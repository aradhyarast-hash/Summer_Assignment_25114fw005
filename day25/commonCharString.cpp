#include <iostream>
using namespace std;

string commonChar(string s1, string s2){
    string s;
    int l1 = s1.length(), l2 = s2.length();
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < l2; j++){
            if(s1[i] == s2[j]){
                s.push_back(s1[i]);
                s.push_back(' ');
            }
        }
    }
    return s;
}
int main() {
    string s1 = "apple";
    string s2 = "grapes";
    cout << commonChar(s1, s2);
    return 0;
}