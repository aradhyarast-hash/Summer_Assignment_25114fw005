#include <iostream>
#include <vector>
using namespace std;

vector<int> primeRange(int start, int end, vector<int> range){
    if(start == 1) start = start + 1;
    for(int i = start; i <= end; i++){
        bool ans = 1;
        for(int j = 2; j <= i/2; j++){
            if((i % j) == 0) {
                ans = 0;
            }
        }
        if(ans == 1) range.push_back(i);
    }
    return range;
}

int main(){
    vector <int> prime;
    vector <int> range = primeRange(1, 35, prime);
    for(int a: range){
        cout << a << endl;
    }
    return 0;
}