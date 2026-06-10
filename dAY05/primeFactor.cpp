// largest prime factor
#include <iostream>
#include <vector>
using namespace std;
bool primechk(int num){
    bool ans = true;
    for(int i = 2; i <= num/2; i++){
        if((num%i) == 0) {
            ans = false;
            break;
        }
    }
    return ans;
}
int largestPrimeFactor(int number){
    int factor = 0, maxfact = 1;
    for(int i = 1; i <= number; i++){
        if((number%i) == 0) {
            factor = i;
            if(primechk(factor)) {
                maxfact = max(maxfact, factor);
            }
        }
    }
    return maxfact;
}
int main(){
    int number = 150 ;
    cout << largestPrimeFactor(number);
    return 0;
}