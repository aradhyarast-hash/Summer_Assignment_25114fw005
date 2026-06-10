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
int main()
{
    int terms = 10;
    for(int i = 0; i < terms; i++){
        cout << fibo(i) << endl;
    }
    return 0;
}