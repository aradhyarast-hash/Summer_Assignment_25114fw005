#include <iostream>
#include <cmath>
using namespace std;

void addition()
{
    float a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;
    cout << "Result : " << a << " + " << b << " = " << a + b << endl;
}

void subtraction()
{
    float a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;
    cout << "Result : " << a << " - " << b << " = " << a - b << endl;
}

void multiplication()
{
    float a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;
    cout << "Result : " << a << " * " << b << " = " << a * b << endl;
}

void division()
{
    float a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;
    if (b == 0)
    {
        cout << "Error! Division by zero." << endl;
        return;
    }
    cout << "Result : " << a << " / " << b << " = " << a / b << endl;
}

void modulusOp()
{
    int a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;
    if (b == 0)
    {
        cout << "Error! Division by zero." << endl;
        return;
    }
    cout << "Result : " << a << " % " << b << " = " << a % b << endl;
}

void power()
{
    float base, exp;
    cout << "Enter base     : ";
    cin >> base;
    cout << "Enter exponent : ";
    cin >> exp;
    cout << "Result : " << base << "^" << exp << " = " << pow(base, exp) << endl;
}

void squareRoot()
{
    float n;
    cout << "Enter number : ";
    cin >> n;
    if (n < 0)
    {
        cout << "Error! Cannot find square root of negative number." << endl;
        return;
    }
    cout << "Result : sqrt(" << n << ") = " << sqrt(n) << endl;
}
void factorial()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    if (n < 0)
    {
        cout << "Error! Factorial of negative number undefined." << endl;
        return;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    cout << "Result : " << n << "! = " << result << endl;
}

void basicMenu()
{
    int ch = -1;
    while (ch != 0)
    {

        cout << "        BASIC OPERATIONS" << endl;

        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. power" << endl;
        cout << "7. squareRoot" << endl;
        cout << "8. factorial"<< endl;
        cout << "0. Back" << endl;

        cout << "Enter choice: ";
        cin >> ch;
        cout <<"=========================="<< endl;
        switch (ch)
        {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            modulusOp();
            break;
        case 6:
            power();
            break;
        case 7:
            squareRoot();
            break;
        case 8:
            factorial();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
        cout << "============================"<< endl;
    }
}
int main()
{
    int choice = -1;
    while (choice != 0) {
        cout << "        MENU DRIVEN CALCULATOR" << endl;
        basicMenu();

        cout << " ---------------------------";
        

    return 0;
    }
}
