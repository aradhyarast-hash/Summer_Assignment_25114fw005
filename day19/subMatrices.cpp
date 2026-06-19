#include <iostream>
using namespace std;
const int col = 3;
void subtractMat(int a1[][col], int a2[][col], int r){
    int sub[r][col];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < col; j++){
            sub[i][j] = a1[i][j] - a2[i][j];
        }
    }

    cout <<"subtracted matrix is "<< endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < col; j++){
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int mat1[3][3] = {
        {1,2,3},
        {7,4,2},
        {99,100,101}
    };
    int mat2[3][3] = {
        {45,46,47},
        {23,24,25},
        {78,79,80}
    };
    subtractMat(mat1, mat2, 3);
    return 0;
}