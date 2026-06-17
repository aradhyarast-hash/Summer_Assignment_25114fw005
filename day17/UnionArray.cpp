// ***************important**********************
// merge both array
// remove duplicates

#include <iostream>
#include <vector>

using namespace std;
vector<int> removeDuplicate(vector<int> &v){
    vector<int> result;
    for(int i = 0; i < v.size(); i++){
        bool isdup = false;
        for(int j = 0; j < result.size(); j++){
            if(v[i] == v[j]){
                isdup = true;
                break;
            }
        }
        if(!isdup) result.push_back(v[i]);
    }
    return result;
}

vector<int> mergeArray(int a1[], int a2[], int sz1, int sz2){
    int sz = sz1 + sz2;
    vector<int> merged;
    int arr[sz];
    for(int i = 0; i < sz1; i++){
        arr[i] = a1[i];
    }
    for(int i = 0; i < sz2; i++){
        arr[i+sz1] = a2[i];
    }
    for(int i = 0; i < sz; i++){
        merged.push_back(arr[i]);
    }
    return merged;
}


int main() {
    
    int sz1 = 6, sz2 = 7, sz = sz1 + sz2;
    int arr1[] = {0,1,2,6,4,5};
    int arr2[] = {6,7,8,2,0,2,12};
    vector <int> m = mergeArray(arr1, arr2, sz1, sz2);
    vector<int> result = removeDuplicate(m);
    for(int i = 0 ; i < result.size(); i++){
        cout << result[i]<< " ";
    }
    
    return 0;
}


