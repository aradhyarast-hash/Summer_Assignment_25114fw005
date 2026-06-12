#include <iostream>
using namespace std;

int fibo(int num)
{
    // base cases
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    // recursion
    return fibo(num - 1) + fibo(num - 2);
}
int main() {
    int n = 4;
    cout << fibo(n);
    return 0;
}