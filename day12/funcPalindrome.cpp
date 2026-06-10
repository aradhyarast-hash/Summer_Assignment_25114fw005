#include <iostream>
#include <string>
using namespace std;
bool checkPalindrome(int num){
    string a = to_string(num);
    bool ans = true;
    int start = 0, end = a.size()-1;
    while(start < end){
        if(a[start] != a[end]) {
            ans = false;
            break;
        } 
        start++;
        end--;
    }
    return ans;
}
int main() {
    cout << checkPalindrome(234565432);
    return 0;
}