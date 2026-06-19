#include <iostream>
using namespace std;
const int col = 3;
void diagonalSum(int m1[][col], int m2[][col], int row)
{
    int dgSum[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                dgSum[i][j] = m1[i][j] + m2[i][j];
            }
            else
            {
                dgSum[i][j] = 0;
            }
        }
    }
    cout << " the diagonal sum matrix :" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << dgSum[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int mat1[3][3] = {
        {1, 2, 3},
        {7, 4, 2},
        {99, 100, 101}};
    int mat2[3][3] = {
        {45, 46, 47},
        {23, 24, 25},
        {78, 79, 80}};
    diagonalSum(mat1, mat2, 3);
    return 0;
}