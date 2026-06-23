#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s = "aradhya";

    unordered_map <char, int> freq;

    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }

    char elem;
    for(int i = 0; i < s.size()-1; i++){
        if(freq[s[i]] == 1) {
            elem = s[i];
            break;
        }
    }
    cout << "the non repeting element is : "<< elem<<endl;
    
    return 0;
}