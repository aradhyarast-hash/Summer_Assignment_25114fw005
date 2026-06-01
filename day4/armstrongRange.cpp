#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> armstrongRange(int n1, int n2){
    vector<int> armstrong;
    for(int i = n1; i <= n2; i++){
        int count = 0;
        int sum = 0, num = i;
        int temp = num;
        while(temp/10){
            count++;
            temp = temp/10;      // ✅ temp changes, not i
        }
        count++;                 
        temp = num;
        while(temp > 0){
            int rem = temp%10;
            int power = 1;
            for(int j = 0; j < count; j++){
                power *= rem;
            }
            sum += power;
            temp = temp/10;      // ✅ temp changes, not i
        }
            
        if((sum)== num) armstrong.push_back(num);
    }
    return armstrong;
}
int main(){
    vector<int> answer;
    answer = armstrongRange(100, 500);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] <<endl;
    }
    return 0;

}