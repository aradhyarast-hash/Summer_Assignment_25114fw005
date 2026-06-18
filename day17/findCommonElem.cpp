#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr1[] = {5, 1, 3, 4, 2};
    int arr2[] = {7, 3, 6, 5, 4};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int i = 0, j = 0;

    cout << "Common elements: ";

    while (i < n1 && j < n2) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return 0;
}