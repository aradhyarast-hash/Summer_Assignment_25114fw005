#include <iostream>
#include <vector>
using namespace std;
vector <int> intersection(int arr1[], int arr2[], int sz1, int sz2){
    vector<int> result;
    for(int i = 0 ; i < sz1; i++){
        for(int j = 0; j < sz2; j++){
            if(arr1[i] == arr2[j]){
                result.push_back(arr1[i]);
                break;
            }
        }
    }
    return result;
}

vector<int> removeDuplicate(vector<int> v){
    vector<int> r;
    for(int i = 0; i < v.size(); i++){
        bool isduplicate = false;
        for(int j = 0 ; j < r.size(); j++){
            if(v[i] == r[j]) {
                isduplicate = true;
                break;
            }
        }
        if(isduplicate == false) {
            r.push_back(v[i]);
        }
    }
    return r;
}

int main() {
    int sz1 = 6, sz2 = 7;
    int arr1[] = {0,1,2,6,4,5};
    int arr2[] = {6,7,8,2,0,2,12};
    vector<int> res = intersection(arr1, arr2, sz1, sz2);
    vector<int> ans = removeDuplicate(res);
    for(int i = 0; i < ans.size(); i++) cout <<ans[i] << " ";

    return 0;
}