#include <iostream>
using namespace std;

string toUpper(string s) {
    for (char& c : s)
        if (c >= 'a' && c <= 'z')
        // A -> 65 ascii code
        // a -> 97 ascii code
        // a - A => 32
            c -= 32;  
    return s;
}
int main() {
    string str = "Aradhya";
    cout << toUpper(str);
    return 0;
}