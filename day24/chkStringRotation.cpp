#include <iostream>
using namespace std;

bool chkRepetition(string str){
    int n = str.length();
    for(int i = 1; i <= n/2; i++){
        if(n%i != 0 ){
            continue;
        }

        string subst = str.substr(0, i);
        string repeted = "";

        int times = n/i;
        for(int j = 0; j < times; j++){
            repeted += subst;
        }

        if(repeted == str){
            return true;
        }
    }
    return false;
}
int main() {
    string str1 = "abcabcabcabc";
    string str2 = "aradhya";
    string str3 = "bonbon";

    cout << chkRepetition(str1) << endl;
    cout << chkRepetition(str2) << endl;
    cout << chkRepetition(str3) << endl;
    return 0;
}