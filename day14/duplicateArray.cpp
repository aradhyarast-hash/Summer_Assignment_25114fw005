#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n = 8;
    int arr[] = {3, 1, 4, 1, 4, 9, 6, 6};
    unordered_map <int, int> duplicate;
    vector <int> dup;
    for(int i = 0; i < 8; i++){
        duplicate[arr[i]]++;
    }
    for(auto a: duplicate){
        if(a.second > 1) dup.push_back(a.first);
    }
    for(int i = 0; i < dup.size(); i++){
        cout << dup[i] << " , ";
    }
    
    return 0;
}