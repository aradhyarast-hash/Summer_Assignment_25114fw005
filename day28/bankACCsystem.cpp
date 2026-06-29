

#include <iostream>
#include <string>
using namespace std;

// ==================== CONSTANTS ======================
const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 5000;
const float MIN_BALANCE = 1000.0;

// ==================== STRUCTS ========================

struct Account
{
    int accountNumber;
    string holderName;
    string accountType; // Savings / Current
    float balance;
    string contact;
    string email;
    bool isActive;
};

struct Transaction
{
    int transID;
    int accountNumber;
    string type; // Deposit / Withdraw / Transfer
    float amount;
    float balanceAfter;
};

// ==================== GLOBAL DATA ====================
Account accounts[MAX_ACCOUNTS];
Transaction transactions[MAX_TRANSACTIONS];

int accCount = 0;
int transCount = 0;
int transIDGen = 1;
int accNumGen = 1001; // auto account number starts from 1001
//  UTILITY

void printLine()
{
    cout << "-------------------------------------------" << endl;
}

void printDoubleLine()
{
    cout << "===========================================" << endl;
}

// find index by account number, returns -1 if not found
int findAccount(int accNo)
{
    for (int i = 0; i < accCount; i++)
        if (accounts[i].accountNumber == accNo)
            return i;
    return -1;
}

// log every transaction
void logTransaction(int accNo, string type, float amount, float balAfter)
{
    Transaction t;
    t.transID = transIDGen++;
    t.accountNumber = accNo;
    t.type = type;
    t.amount = amount;
    t.balanceAfter = balAfter;
    transactions[transCount++] = t;
}

// ============== ACCOUNT MANAGEMENT ===================

// 1. Create Account
void createAccount()
{
    if (accCount >= MAX_ACCOUNTS)
    {
        cout << "Bank is full! Cannot create more accounts." << endl;
        return;
    }

    Account a;
    a.accountNumber = accNumGen++; // auto-assigned
    a.isActive = true;

    cout << "\n--- CREATE ACCOUNT ---" << endl;
    cin.ignore();
    cout << "Enter Holder Name    : ";
    getline(cin, a.holderName);
    cout << "Enter Account Type   : " << endl;
    cout << "  1. Savings" << endl;
    cout << "  2. Current" << endl;
    cout << "  Choice             : ";
    int ch;
    cin >> ch;
    a.accountType = (ch == 1) ? "Savings" : "Current";

    cout << "Enter Initial Deposit: Rs. ";
    cin >> a.balance;

    if (a.balance < MIN_BALANCE)
    {
        cout << "Minimum opening balance is Rs. " << MIN_BALANCE << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Contact        : ";
    getline(cin, a.contact);
    cout << "Enter Email          : ";
    getline(cin, a.email);

    accounts[accCount++] = a;
    logTransaction(a.accountNumber, "Opening Deposit", a.balance, a.balance);

    printLine();
    cout << "Account created successfully!" << endl;
    cout << "Your Account Number  : " << a.accountNumber << endl;
    printLine();
}

// 2. Display 1 Account
void displayAccount(int idx)
{
    printLine();
    cout << "Account Number : " << accounts[idx].accountNumber << endl;
    cout << "Holder Name    : " << accounts[idx].holderName << endl;
    cout << "Account Type   : " << accounts[idx].accountType << endl;
    cout << "Balance        : Rs. " << accounts[idx].balance << endl;
    cout << "Contact        : " << accounts[idx].contact << endl;
    cout << "Email          : " << accounts[idx].email << endl;
    cout << "Status         : " << (accounts[idx].isActive ? "ACTIVE" : "INACTIVE") << endl;
    printLine();
}

// 3. Display All Accounts
void displayAllAccounts()
{
    if (accCount == 0)
    {
        cout << "No accounts found!" << endl;
        return;
    }
    printDoubleLine();
    cout << "        ALL ACCOUNTS" << endl;
    printDoubleLine();
    for (int i = 0; i < accCount; i++)
        displayAccount(i);
}

// 4. Search by Account Number
void searchAccount()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
        cout << "Account not found!" << endl;
    else
        displayAccount(idx);
}

// 5. Search by Name
void searchByName()
{
    cin.ignore();
    string name;
    cout << "Enter Holder Name: ";
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < accCount; i++)
    {
        if (accounts[i].holderName == name)
        {
            displayAccount(i);
            found = true;
        }
    }
    if (!found)
        cout << "No account found with that name!" << endl;
}

// 6. Update Account
void updateAccount()
{
    int accNo;
    cout << "Enter Account Number to update: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    if (!accounts[idx].isActive)
    {
        cout << "Account is inactive!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter new Contact : ";
    getline(cin, accounts[idx].contact);
    cout << "Enter new Email   : ";
    getline(cin, accounts[idx].email);
    cout << "Account updated successfully!" << endl;
}

// 7. Delete / Close Account
void deleteAccount()
{
    int accNo;
    cout << "Enter Account Number to close: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }

    if (accounts[idx].balance > 0)
    {
        cout << "Remaining balance Rs. " << accounts[idx].balance << " will be returned." << endl;
    }

    for (int i = idx; i < accCount - 1; i++)
        accounts[i] = accounts[i + 1];
    accCount--;
    cout << "Account closed successfully!" << endl;
}

// 8. Activate Account
void activateAccount()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    accounts[idx].isActive = true;
    cout << "Account activated!" << endl;
}

// 9. Deactivate Account
void deactivateAccount()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    accounts[idx].isActive = false;
    cout << "Account deactivated!" << endl;
}

// ================= TRANSACTIONS ======================

// 1. Deposit
void deposit()
{
    int accNo;
    float amount;
    cout << "\n--- DEPOSIT ---" << endl;
    cout << "Enter Account Number : ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    if (!accounts[idx].isActive)
    {
        cout << "Account is inactive!" << endl;
        return;
    }

    cout << "Enter Amount to Deposit: Rs. ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }

    accounts[idx].balance += amount;
    logTransaction(accNo, "Deposit", amount, accounts[idx].balance);

    printLine();
    cout << "Rs. " << amount << " deposited successfully!" << endl;
    cout << "New Balance: Rs. " << accounts[idx].balance << endl;
    printLine();
}

// 2. Withdraw
void withdraw()
{
    int accNo;
    float amount;
    cout << "\n--- WITHDRAW ---" << endl;
    cout << "Enter Account Number  : ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    if (!accounts[idx].isActive)
    {
        cout << "Account is inactive!" << endl;
        return;
    }

    cout << "Enter Amount to Withdraw: Rs. ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }

    if (accounts[idx].balance - amount < MIN_BALANCE)
    {
        cout << "Insufficient balance!" << endl;
        cout << "Minimum balance of Rs. " << MIN_BALANCE << " must be maintained." << endl;
        cout << "Max you can withdraw: Rs. " << (accounts[idx].balance - MIN_BALANCE) << endl;
        return;
    }

    accounts[idx].balance -= amount;
    logTransaction(accNo, "Withdrawal", amount, accounts[idx].balance);

    printLine();
    cout << "Rs. " << amount << " withdrawn successfully!" << endl;
    cout << "New Balance: Rs. " << accounts[idx].balance << endl;
    printLine();
}

// 3. Transfer
void transfer()
{
    int fromAcc, toAcc;
    float amount;
    cout << "\n--- TRANSFER ---" << endl;
    cout << "Enter Sender Account Number  : ";
    cin >> fromAcc;
    cout << "Enter Receiver Account Number: ";
    cin >> toAcc;

    int fromIdx = findAccount(fromAcc);
    int toIdx = findAccount(toAcc);

    if (fromIdx == -1)
    {
        cout << "Sender account not found!" << endl;
        return;
    }
    if (toIdx == -1)
    {
        cout << "Receiver account not found!" << endl;
        return;
    }
    if (!accounts[fromIdx].isActive)
    {
        cout << "Sender account is inactive!" << endl;
        return;
    }
    if (!accounts[toIdx].isActive)
    {
        cout << "Receiver account is inactive!" << endl;
        return;
    }
    if (fromAcc == toAcc)
    {
        cout << "Cannot transfer to same account!" << endl;
        return;
    }

    cout << "Enter Amount to Transfer: Rs. ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
        return;
    }

    if (accounts[fromIdx].balance - amount < MIN_BALANCE)
    {
        cout << "Insufficient balance for transfer!" << endl;
        cout << "Max you can transfer: Rs. " << (accounts[fromIdx].balance - MIN_BALANCE) << endl;
        return;
    }

    accounts[fromIdx].balance -= amount;
    accounts[toIdx].balance += amount;

    logTransaction(fromAcc, "Transfer Out", amount, accounts[fromIdx].balance);
    logTransaction(toAcc, "Transfer In", amount, accounts[toIdx].balance);

    printLine();
    cout << "Transfer successful!" << endl;
    cout << "Rs. " << amount << " sent to Account " << toAcc << endl;
    cout << "Your new Balance: Rs. " << accounts[fromIdx].balance << endl;
    printLine();
}

// 4. Check Balance
void checkBalance()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }
    printLine();
    cout << "Account Holder : " << accounts[idx].holderName << endl;
    cout << "Account Number : " << accounts[idx].accountNumber << endl;
    cout << "Balance        : Rs. " << accounts[idx].balance << endl;
    printLine();
}

// 5. Mini Statement (last 5 transactions)
void miniStatement()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    if (findAccount(accNo) == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }

    cout << "\n--- MINI STATEMENT (Last 5) ---" << endl;
    printLine();

    int shown = 0;
    for (int i = transCount - 1; i >= 0 && shown < 5; i--)
    {
        if (transactions[i].accountNumber == accNo)
        {
            cout << "Trans ID  : " << transactions[i].transID << endl;
            cout << "Type      : " << transactions[i].type << endl;
            cout << "Amount    : Rs. " << transactions[i].amount << endl;
            cout << "Balance   : Rs. " << transactions[i].balanceAfter << endl;
            printLine();
            shown++;
        }
    }
    if (shown == 0)
        cout << "No transactions found!" << endl;
}

// 6. Full Statement
void fullStatement()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx == -1)
    {
        cout << "Account not found!" << endl;
        return;
    }

    printDoubleLine();
    cout << "   FULL STATEMENT - " << accounts[idx].holderName << endl;
    printDoubleLine();

    bool any = false;
    for (int i = 0; i < transCount; i++)
    {
        if (transactions[i].accountNumber == accNo)
        {
            any = true;
            cout << "Trans ID  : " << transactions[i].transID << endl;
            cout << "Type      : " << transactions[i].type << endl;
            cout << "Amount    : Rs. " << transactions[i].amount << endl;
            cout << "Balance   : Rs. " << transactions[i].balanceAfter << endl;
            printLine();
        }
    }
    if (!any)
        cout << "No transactions found!" << endl;
}

// ==================== MENUS ==========================

void accountMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "       ACCOUNT MANAGEMENT" << endl;
        printDoubleLine();
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Search by Acc Number" << endl;
        cout << "4. Search by Name" << endl;
        cout << "5. Update Account" << endl;
        cout << "6. Close Account" << endl;
        cout << "7. Activate Account" << endl;
        cout << "8. Deactivate Account" << endl;
        cout << "0. Back" << endl;
        printLine();
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            createAccount();
            break;
        case 2:
            displayAllAccounts();
            break;
        case 3:
            searchAccount();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            updateAccount();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            activateAccount();
            break;
        case 8:
            deactivateAccount();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void transactionMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "         TRANSACTIONS" << endl;
        printDoubleLine();
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Mini Statement" << endl;
        cout << "6. Full Statement" << endl;
        cout << "0. Back" << endl;
        printLine();
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            transfer();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            miniStatement();
            break;
        case 6:
            fullStatement();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

// ===================== MAIN ==========================

int main()
{
    int choice = -1;
    while (choice != 3)
    {
        printDoubleLine();
        cout << "    BANK ACCOUNT MANAGEMENT SYSTEM" << endl;
        printDoubleLine();
        cout << "1. Account Management" << endl;
        cout << "2. Transactions" << endl;
        cout << "3. Exit" << endl;
        printDoubleLine();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            accountMenu();
            break;
        case 2:
            transactionMenu();
            break;
        case 3:
            cout << "Thank you for using Bank Management System!" << endl;
            exit(0);
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}