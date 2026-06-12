#include <iostream>
using namespace std;
bool checkPalin(int num){
    int n = num, cnt = 0;
    while(num == 0){
        int r = num%10;
        num = num/10;
        cnt++;
    }
    int st = 0, end = cnt-1;
    string numb = to_string(n);
    while(st < end){
        if(numb[st] != numb[end]) return false;
        st++;
        end--;
    }
    return true;
}


int main() {
    cout << checkPalin(3443);
    return 0;
}