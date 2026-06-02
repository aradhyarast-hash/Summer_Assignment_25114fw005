#include <iostream>
#include <vector>
using namespace std;
vector<int> factors(int number){
    vector <int> factor;
    for(int i = 1; i <= number; i++){
        if((number%i) == 0) factor.push_back(i);
    }
    return factor;
}
int main(){
    int n = 8;
    vector<int> ans;
    ans = factors(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]<< endl;
    }
    return 0;
}