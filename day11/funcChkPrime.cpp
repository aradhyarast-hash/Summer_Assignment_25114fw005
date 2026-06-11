#include <iostream>
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

int main() {
    cout << primechk(7);
    return 0;
}