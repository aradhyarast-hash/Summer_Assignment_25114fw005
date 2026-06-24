#include <iostream>
using namespace std;
int main() {

    string s = "Its day 23 of doing assignments given by my college";
    int start = 0, end = 0;
    int maxi = end - start;
    string word;
    while(start <= end && end < s.size()){
        if(s[end] == ' '){
            if((end-start) > maxi){
                maxi = end-start;
                word = s.substr(start, end - start);
            }
            start = end+1;
            end++;
        }
        else end++;
    }
    cout << "the longest word in string is : "<< word;

    return 0;
}