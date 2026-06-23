#include <iostream>
#include <algorithm>
using namespace std;

bool chkAnagram(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    bool ans = false;
    if(s1 == s2) {
        ans = true;
    }
    return ans;
}
int main() {
    string s1 = "triangle";
    string s2 = "integral";
    cout << chkAnagram(s1, s2) << endl;
    return 0;
}