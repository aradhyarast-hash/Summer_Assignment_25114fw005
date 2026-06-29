// =====================================================
//         LIBRARY MANAGEMENT SYSTEM IN C++
// =====================================================

#include <iostream>
#include <string>
using namespace std;

// ===================== CONSTANTS =====================
const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 100;
const int MAX_RECORDS = 200;
const int MAX_ISSUE = 3;     // max books per member
const int ISSUE_DAYS = 14;   // allowed days
const int FINE_PER_DAY = 15; // fine in rupees

// ===================== STRUCTS =======================

struct Book
{
    int bookID;
    string title;
    string author;
    string genre;
    float price;
    int totalCopies;
    int availableCopies;
};

struct Member
{
    int memberID;
    string name;
    string contact;
    int booksIssued;
    int fineAmount; 
};

struct IssueRecord
{
    int recordID;
    int bookID;
    int memberID;
    int issuedDays; // days since issued (simulate)
    bool returned;
};

Book books[MAX_BOOKS];
Member members[MAX_MEMBERS];
IssueRecord records[MAX_RECORDS];

int bookCount = 0;
int memberCount = 0;
int recordCount = 0;
int recordIDGen = 1;

void printLine()
{
    cout << "-------------------------------------------" << endl;
}
void printDoubleLine()
{
    cout << "===========================================" << endl;
}

int findBookIndex(int id)
{
    for (int i = 0; i < bookCount; i++)
        if (books[i].bookID == id)
            return i;
    return -1;
}

int findMemberIndex(int id)
{
    for (int i = 0; i < memberCount; i++)
        if (members[i].memberID == id)
            return i;
    return -1;
}

// ==================== BOOK FUNCTIONS =================

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }
    Book b;
    cout << "\n--- ADD BOOK ---" << endl;
    cout << "Enter Book ID : ";
    cin >> b.bookID;

    if (findBookIndex(b.bookID) != -1)
    {
        cout << "Book ID already exists!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Title       : ";
    getline(cin, b.title);
    cout << "Enter Author      : ";
    getline(cin, b.author);
    cout << "Enter Genre       : ";
    getline(cin, b.genre);
    cout << "Enter Price       : ";
    cin >> b.price;
    cout << "Enter Total Copies: ";
    cin >> b.totalCopies;
    b.availableCopies = b.totalCopies;

    books[bookCount++] = b;
    cout << "Book added successfully!" << endl;
}

void displayBook(int idx)
{
    printLine();
    cout << "Book ID       : " << books[idx].bookID << endl;
    cout << "Title         : " << books[idx].title << endl;
    cout << "Author        : " << books[idx].author << endl;
    cout << "Genre         : " << books[idx].genre << endl;
    cout << "Price         : " << books[idx].price << endl;
    cout << "Total Copies  : " << books[idx].totalCopies << endl;
    cout << "Available     : " << books[idx].availableCopies << endl;
    printLine();
}

void displayAllBooks()
{
    if (bookCount == 0)
    {
        cout << "No books in library!" << endl;
        return;
    }
    printDoubleLine();
    cout << "         ALL BOOKS IN LIBRARY" << endl;
    printDoubleLine();
    for (int i = 0; i < bookCount; i++)
        displayBook(i);
}

void searchBookByID()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    int idx = findBookIndex(id);
    if (idx == -1)
        cout << "Book not found!" << endl;
    else
        displayBook(idx);
}

void searchBookByTitle()
{
    cin.ignore();
    string title;
    cout << "Enter Title to search: ";
    getline(cin, title);
    bool found = false;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == title)
        {
            displayBook(i);
            found = true;
        }
    }
    if (!found)
        cout << "No book found with that title!" << endl;
}

void searchBookByAuthor()
{
    cin.ignore();
    string author;
    cout << "Enter Author to search: ";
    getline(cin, author);
    bool found = false;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].author == author)
        {
            displayBook(i);
            found = true;
        }
    }
    if (!found)
        cout << "No book found by that author!" << endl;
}

void updateBook()
{
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;
    int idx = findBookIndex(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter new Title       : ";
    getline(cin, books[idx].title);
    cout << "Enter new Author      : ";
    getline(cin, books[idx].author);
    cout << "Enter new Genre       : ";
    getline(cin, books[idx].genre);
    cout << "Enter new Price       : ";
    cin >> books[idx].price;
    cout << "Enter new Total Copies: ";
    cin >> books[idx].totalCopies;
    cout << "Book updated!" << endl;
}

void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    int idx = findBookIndex(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    if (books[idx].availableCopies != books[idx].totalCopies)
    {
        cout << "Cannot delete! Some copies are currently issued." << endl;
        return;
    }
    for (int i = idx; i < bookCount - 1; i++)
        books[i] = books[i + 1];
    bookCount--;
    cout << "Book deleted successfully!" << endl;
}

void sortBooksByTitle()
{
    for (int i = 0; i < bookCount - 1; i++)
        for (int j = 0; j < bookCount - i - 1; j++)
            if (books[j].title > books[j + 1].title)
                swap(books[j], books[j + 1]);
    cout << "Books sorted by Title:" << endl;
    displayAllBooks();
}

void sortBooksByPrice()
{
    for (int i = 0; i < bookCount - 1; i++)
        for (int j = 0; j < bookCount - i - 1; j++)
            if (books[j].price > books[j + 1].price)
                swap(books[j], books[j + 1]);
    cout << "Books sorted by Price:" << endl;
    displayAllBooks();
}

void checkAvailability()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBookIndex(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Title     : " << books[idx].title << endl;
    cout << "Available : " << books[idx].availableCopies << " / " << books[idx].totalCopies << endl;
    if (books[idx].availableCopies > 0)
        cout << "Status    : AVAILABLE" << endl;
    else
        cout << "Status    : NOT AVAILABLE" << endl;
}

// MEMBER FUNCTIONS 

void addMember()
{
    if (memberCount >= MAX_MEMBERS)
    {
        cout << "Member limit reached!" << endl;
        return;
    }
    Member m;
    cout << "\n--- ADD MEMBER ---" << endl;
    cout << "Enter Member ID  : ";
    cin >> m.memberID;

    if (findMemberIndex(m.memberID) != -1)
    {
        cout << "Member ID already exists!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Name       : ";
    getline(cin, m.name);
    cout << "Enter Contact    : ";
    getline(cin, m.contact);
    m.booksIssued = 0;
    m.fineAmount = 0;

    members[memberCount++] = m;
    cout << "Member registered successfully!" << endl;
}

void displayMember(int idx)
{
    printLine();
    cout << "Member ID     : " << members[idx].memberID << endl;
    cout << "Name          : " << members[idx].name << endl;
    cout << "Contact       : " << members[idx].contact << endl;
    cout << "Books Issued  : " << members[idx].booksIssued << endl;
    cout << "Fine Amount   : Rs. " << members[idx].fineAmount << endl;
    printLine();
}

void displayAllMembers()
{
    if (memberCount == 0)
    {
        cout << "No members registered!" << endl;
        return;
    }
    printDoubleLine();
    cout << " ALL MEMBERS" << endl;
    printDoubleLine();
    for (int i = 0; i < memberCount; i++)
        displayMember(i);
}

void searchMember()
{
    int id;
    cout << "Enter Member ID: ";
    cin >> id;
    int idx = findMemberIndex(id);
    if (idx == -1)
        cout << "Member not found!" << endl;
    else
        displayMember(idx);
}

void updateMember()
{
    int id;
    cout << "Enter Member ID to update: ";
    cin >> id;
    int idx = findMemberIndex(id);
    if (idx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }
    cin.ignore();
    cout << "Enter new Name   : ";
    getline(cin, members[idx].name);
    cout << "Enter new Contact: ";
    getline(cin, members[idx].contact);
    cout << "Member updated!" << endl;
}

void deleteMember()
{
    int id;
    cout << "Enter Member ID to delete: ";
    cin >> id;
    int idx = findMemberIndex(id);
    if (idx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }
    if (members[idx].booksIssued > 0)
    {
        cout << "Cannot delete! Member has books issued." << endl;
        return;
    }
    if (members[idx].fineAmount > 0)
    {
        cout << "Cannot delete! Member has pending fine of Rs. " << members[idx].fineAmount << endl;
        return;
    }
    for (int i = idx; i < memberCount - 1; i++)
        members[i] = members[i + 1];
    memberCount--;
    cout << "Member deleted successfully!" << endl;
}

// ==================== ISSUE / RETURN =================

void issueBook()
{
    int bID, mID;
    cout << "\n--- ISSUE BOOK ---" << endl;
    cout << "Enter Book ID  : ";
    cin >> bID;
    cout << "Enter Member ID: ";
    cin >> mID;

    int bIdx = findBookIndex(bID);
    int mIdx = findMemberIndex(mID);

    if (bIdx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }
    if (mIdx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }

    if (books[bIdx].availableCopies <= 0)
    {
        cout << "No copies available right now!" << endl;
        return;
    }
    if (members[mIdx].booksIssued >= MAX_ISSUE)
    {
        cout << "Member already has " << MAX_ISSUE << " books. Cannot issue more!" << endl;
        return;
    }
    if (members[mIdx].fineAmount > 0)
    {
        cout << "Member has pending fine of Rs. " << members[mIdx].fineAmount << ". Please clear fine first!" << endl;
        return;
    }

    // Check if already issued same book
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i].bookID == bID && records[i].memberID == mID && !records[i].returned)
        {
            cout << "This member already has this book!" << endl;
            return;
        }
    }

    IssueRecord r;
    r.recordID = recordIDGen++;
    r.bookID = bID;
    r.memberID = mID;
    r.issuedDays = 0;
    r.returned = false;

    records[recordCount++] = r;
    books[bIdx].availableCopies--;
    members[mIdx].booksIssued++;

    cout << "Book issued successfully!" << endl;
    cout << "Please return within " << ISSUE_DAYS << " days." << endl;
}

void returnBook()
{
    int bID, mID, daysHeld;
    cout << "\n--- RETURN BOOK ---" << endl;
    cout << "Enter Book ID  : ";
    cin >> bID;
    cout << "Enter Member ID: ";
    cin >> mID;
    cout << "Enter Days Held: ";
    cin >> daysHeld;

    int bIdx = findBookIndex(bID);
    int mIdx = findMemberIndex(mID);

    if (bIdx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }
    if (mIdx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i].bookID == bID && records[i].memberID == mID && !records[i].returned)
        {
            records[i].returned = true;
            records[i].issuedDays = daysHeld;
            found = true;

            books[bIdx].availableCopies++;
            members[mIdx].booksIssued--;

            int overdue = daysHeld - ISSUE_DAYS;
            if (overdue > 0)
            {
                int fine = overdue * FINE_PER_DAY;
                members[mIdx].fineAmount += fine;
                cout << "Book returned!" << endl;
                cout << "Overdue by " << overdue << " days." << endl;
                cout << "Fine applied: Rs. " << fine << endl;
            }
            else
            {
                cout << "Book returned on time! Thank you." << endl;
            }
            break;
        }
    }
    if (!found)
        cout << "No active issue record found for this book and member!" << endl;
}

void displayIssuedBooks()
{
    cout << "\n--- ALL CURRENTLY ISSUED BOOKS ---" << endl;
    bool any = false;
    for (int i = 0; i < recordCount; i++)
    {
        if (!records[i].returned)
        {
            any = true;
            printLine();
            cout << "Record ID  : " << records[i].recordID << endl;
            int bIdx = findBookIndex(records[i].bookID);
            int mIdx = findMemberIndex(records[i].memberID);
            cout << "Book       : " << (bIdx != -1 ? books[bIdx].title : "Unknown") << endl;
            cout << "Member     : " << (mIdx != -1 ? members[mIdx].name : "Unknown") << endl;
        }
    }
    if (!any)
        cout << "No books are currently issued." << endl;
}

void displayMemberIssuedBooks()
{
    int mID;
    cout << "Enter Member ID: ";
    cin >> mID;
    int mIdx = findMemberIndex(mID);
    if (mIdx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }

    cout << "\nBooks issued to: " << members[mIdx].name << endl;
    bool any = false;
    for (int i = 0; i < recordCount; i++)
    {
        if (records[i].memberID == mID && !records[i].returned)
        {
            any = true;
            int bIdx = findBookIndex(records[i].bookID);
            cout << "- " << (bIdx != -1 ? books[bIdx].title : "Unknown") << " (ID: " << records[i].bookID << ")" << endl;
        }
    }
    if (!any)
        cout << "No books currently issued." << endl;
}

// ==================== FINE FUNCTIONS =================

void displayFine()
{
    int id;
    cout << "Enter Member ID: ";
    cin >> id;
    int idx = findMemberIndex(id);
    if (idx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }
    cout << "Member : " << members[idx].name << endl;
    cout << "Fine   : Rs. " << members[idx].fineAmount << endl;
}

void payFine()
{
    int id;
    cout << "Enter Member ID: ";
    cin >> id;
    int idx = findMemberIndex(id);
    if (idx == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }
    if (members[idx].fineAmount == 0)
    {
        cout << "No pending fine for this member." << endl;
        return;
    }
    cout << "Fine of Rs. " << members[idx].fineAmount << " cleared!" << endl;
    members[idx].fineAmount = 0;
}

// ==================== REPORTS ========================

void availableBooksReport()
{
    cout << "\n--- AVAILABLE BOOKS REPORT ---" << endl;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].availableCopies > 0)
        {
            cout << books[i].bookID << " | " << books[i].title
                 << " | Available: " << books[i].availableCopies << endl;
        }
    }
}

void totalFineCollectedReport()
{
    int total = 0;
    for (int i = 0; i < memberCount; i++)
        total += members[i].fineAmount;
    cout << "\nTotal Pending Fine in System: Rs. " << total << endl;
}

void mostIssuedBook()
{
    if (bookCount == 0)
    {
        cout << "No books!" << endl;
        return;
    }
    int count[MAX_BOOKS] = {0};
    for (int i = 0; i < recordCount; i++)
    {
        int idx = findBookIndex(records[i].bookID);
        if (idx != -1)
            count[idx]++;
    }
    int maxIdx = 0;
    for (int i = 1; i < bookCount; i++)
        if (count[i] > count[maxIdx])
            maxIdx = i;
    cout << "\nMost Issued Book: " << books[maxIdx].title
         << " (Issued " << count[maxIdx] << " times)" << endl;
}

void memberWithMostBooks()
{
    if (memberCount == 0)
    {
        cout << "No members!" << endl;
        return;
    }
    int maxIdx = 0;
    for (int i = 1; i < memberCount; i++)
        if (members[i].booksIssued > members[maxIdx].booksIssued)
            maxIdx = i;
    cout << "\nMember holding most books: " << members[maxIdx].name
         << " (" << members[maxIdx].booksIssued << " books)" << endl;
}

// ==================== MENUS ==========================

void bookMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "         BOOK MANAGEMENT" << endl;
        printDoubleLine();
        cout << "1.  Add Book" << endl;
        cout << "2.  Display All Books" << endl;
        cout << "3.  Search by ID" << endl;
        cout << "4.  Search by Title" << endl;
        cout << "5.  Search by Author" << endl;
        cout << "6.  Update Book" << endl;
        cout << "7.  Delete Book" << endl;
        cout << "8.  Sort Books" << endl;
        cout << "9.  Check Availability" << endl;
        cout << "0.  Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayAllBooks();
            break;
        case 3:
            searchBookByID();
            break;
        case 4:
            searchBookByTitle();
            break;
        case 5:
            searchBookByAuthor();
            break;
        case 6:
            updateBook();
            break;
        case 7:
            deleteBook();
            break;
        case 8:
        {
            int s;
            cout << "1. Sort by Title  2. Sort by Price: ";
            cin >> s;
            if (s == 1)
                sortBooksByTitle();
            else
                sortBooksByPrice();
            break;
        }
        case 9:
            checkAvailability();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void memberMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "         MEMBER MANAGEMENT" << endl;
        printDoubleLine();
        cout << "1. Add Member" << endl;
        cout << "2. Display All Members" << endl;
        cout << "3. Search Member" << endl;
        cout << "4. Update Member" << endl;
        cout << "5. Delete Member" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            addMember();
            break;
        case 2:
            displayAllMembers();
            break;
        case 3:
            searchMember();
            break;
        case 4:
            updateMember();
            break;
        case 5:
            deleteMember();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void issueMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "         ISSUE / RETURN" << endl;
        printDoubleLine();
        cout << "1. Issue Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. View All Issued Books" << endl;
        cout << "4. View Member Issued Books" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            issueBook();
            break;
        case 2:
            returnBook();
            break;
        case 3:
            displayIssuedBooks();
            break;
        case 4:
            displayMemberIssuedBooks();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void fineMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "         FINE MANAGEMENT" << endl;
        printDoubleLine();
        cout << "1. View Member Fine" << endl;
        cout << "2. Pay Fine" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            displayFine();
            break;
        case 2:
            payFine();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void reportsMenu()
{
    int ch = -1;
    while (ch != 0)
    {
        printDoubleLine();
        cout << "           REPORTS" << endl;
        printDoubleLine();
        cout << "1. Available Books" << endl;
        cout << "2. Most Issued Book" << endl;
        cout << "3. Member with Most Books" << endl;
        cout << "4. Total Fine in System" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            availableBooksReport();
            break;
        case 2:
            mostIssuedBook();
            break;
        case 3:
            memberWithMostBooks();
            break;
        case 4:
            totalFineCollectedReport();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

// main

int main()
{
    int choice = 0;
    while (choice != 6)
    {
        printDoubleLine();
        cout << "     LIBRARY MANAGEMENT SYSTEM" << endl;
        printDoubleLine();
        cout << "1. Book Management" << endl;
        cout << "2. Member Management" << endl;
        cout << "3. Issue / Return" << endl;
        cout << "4. Fine Management" << endl;
        cout << "5. Reports" << endl;
        cout << "6. Exit" << endl;
        printDoubleLine();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookMenu();
            break;
        case 2:
            memberMenu();
            break;
        case 3:
            issueMenu();
            break;
        case 4:
            fineMenu();
            break;
        case 5:
            reportsMenu();
            break;
        case 6:
            cout << "Thank you for using Library Management System!" << endl;
            exit(0);
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}