#include <iostream>
using namespace std;

void printLine()
{
    cout << "-------------------------------------------" << endl;
}
void printDoubleLine()
{
    cout << "===========================================" << endl;
}

int strLen(string s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

void toUpperCase(string s)
{
    for (int i = 0; i < strLen(s); i++)
    {
        s[i] = toupper(s[i]);
    }
    cout << "Uppercase : " << s << endl;
}

void toLowerCase(string s)
{
    for (int i = 0; i < strLen(s); i++)
    {
        s[i] = tolower(s[i]);
    }

    cout << "LowerCase : " << s << endl;
}

void reverseString(string s)
{

    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    cout << "Reversed: " << s << endl;
}

void isPalindrome(string s)
{
    string clean = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            clean += tolower(s[i]);
    }

    string rev = clean;
    int left = 0, right = rev.length() - 1;
    while (left < right)
    {
        swap(rev[left], rev[right]);
        left++;
        right--;
    }
    if (clean == rev)
        cout << "\"" << s << "\" IS a palindrome." << endl;
    else
        cout << "\"" << s << "\" is NOT a palindrome." << endl;
}

void showMenu()
{
    printDoubleLine();
    cout << "      BASIC STRING OPERATIONS" << endl;
    printDoubleLine();
    cout << "1. String Length" << endl;
    cout << "2. To Uppercase" << endl;
    cout << "3. To Lowercase" << endl;
    cout << "4. Reverse String" << endl;
    cout << "5. Check Palindrome" << endl;
    cout << "0. Exit" << endl;
    printDoubleLine();
}
int main()
{
    int choice = -1;
    string str;

    while (choice != 0)
    {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear leftover newline before getline

        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter a string: ";
            getline(cin, str);
            printLine();
        }

        switch (choice)
        {
        case 1:
            cout << strLen(str) << endl;
            break;
        case 2:
            toUpperCase(str);
            break;
        case 3:
            toLowerCase(str);
            break;
        case 4:
            reverseString(str);
            break;
        case 5:
            isPalindrome(str);
            break;
        case 0:
            cout << "Thank you for using String Operations!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
