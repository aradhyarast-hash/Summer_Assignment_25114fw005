#include <iostream>
using namespace std;
const int col = 3;

void addMatrice(int m1[][col], int m2[][col], int row){
    int m[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            m[i][j] = m1[i][j] + m2[i][j];
        }
    }


    cout << "the sum of the matrices is "<< endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << m[i][j] << " ";
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
    addMatrice(mat1, mat2, 3);
    return 0;
}