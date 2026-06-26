#include <iostream>
using namespace std;
// guess the number from 0 to 100

int main() {
    int num = 56;
    int guess = -1;
    while(guess != num){
        cout << "enter the guess: "<< endl;
        cin >> guess;
        if(guess < 0 || guess > 100){
            cout << "please enter a number in 0 to 100 range"<< endl;
        }
        if(guess < num) {
            cout << "larger" << endl;
        }
        else if(guess > num){
            cout << "smaller"<< endl;
        }
        else cout << "YOU WON!" << endl;
    }
    return 0;
}