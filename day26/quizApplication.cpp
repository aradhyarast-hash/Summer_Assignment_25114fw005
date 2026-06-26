#include <iostream>
using namespace std;

//  quiz application
int main()
{
    string questions[] = {
        "What is the capital of India?",
        "How many days are there in a week?",
        "Which language is NOT used for DSA?"};

    string options[][4] = {
        {"Mumbai", "Delhi", "Lucknow", "Jaipur"},
        {"5", "6", "7", "8"},
        {"Python", "Java", "C++", "HTML"}};

    char answers[] = {'B', 'C', 'D'};
    int score = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << questions[i] << endl;
        char letters[] = {'A', 'B', 'C', 'D'};
        for (int j = 0; j < 4; j++)
        {
            cout << letters[j] << ". " << options[i][j] << endl;
        }
        char choice;
        cout << "enter you answer : ";
        cin >> choice;
        if (choice == answers[i])
        {
            score++;
            cout << "correct!" << endl;
        }
        else
        {
            cout << "Wrong!" << endl;
            cout << "Correct Answer : " << answers[i] << endl;
        }
    }
    cout << "your score is : " << score;
    return 0;
}