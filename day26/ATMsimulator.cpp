#include <iostream>
using namespace std;

// 1.check balance
// 2.deposite money
// 3.withdraw money
// 4.exit

int chk_balance(int balance){
    cout << "your current balance : "<< endl;
    return balance;
}

void deposite(int b, int balance){
    balance += b;
    cout << "amount deposited : "<< b<<endl;
}

void withdraw(int money, int balance){
    balance -= money;
    cout << "amount withdrawn : "<< money << endl;
}

void exit(){
    cout << "THANK YOU!" << endl;
}

int main() {
    cout << "===========ATM MENU==========" << endl;
    int balance = 0;
    int select = 0;
    cout << "select a number : " <<endl;
    cout << "1. Check Balance"<< endl;
    cout << "2. Deposite Money"<< endl;
    cout << "3. Withdraw Money"<< endl;
    cout << "4. Exit"<< endl;
    while(select != 4){
        cout << "enter your choice: "<< endl;
        cin >> select;
        if(select == 1){
            chk_balance(balance);
        }
        else if(select == 2){
            int amount;
            cout << "enter the amount you want to deposite : " << endl;
            cin >> amount;
            deposite(amount, balance);
        }
        else if(select == 3){
            int amount;
            cout << "enter the amount you want to withdraw : " << endl;
            cin >> amount;
            withdraw(amount, balance);
        }
        else if(select == 4){
            exit();
        }
        else{
            cout<< "please select a valid choice..." <<endl;
        }
    }
    return 0;
}