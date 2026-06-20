#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter order of matrix: ";
    cin >> n;

    int a[100][100];

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool symmetric = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                symmetric = false;
                break;
            }
        }
        if(!symmetric)
            break;
    }

    if(symmetric)
        cout << "The matrix is symmetric.";
    else
        cout << "The matrix is not symmetric.";

    return 0;
}