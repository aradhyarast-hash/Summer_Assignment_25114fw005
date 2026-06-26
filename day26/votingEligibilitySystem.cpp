#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "enter your age here: "<< endl;
    cin >> age;
    if(age <= 0){
        cout << "you do not exist" << endl;;
    }
    else if(age < 18){
        cout << "you are not eligible to vote." << endl;
    }
    else{
        cout << "you are eligible to vote." << endl;
    }
    return 0;
}