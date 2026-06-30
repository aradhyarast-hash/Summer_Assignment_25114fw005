

#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

//  PARALLEL ARRAYS 
int bookIDs[MAX_BOOKS];
string titles[MAX_BOOKS];
string authors[MAX_BOOKS];
int totalCopies[MAX_BOOKS];
int availableCopies[MAX_BOOKS];
bool isIssued[MAX_BOOKS];   // simple flag: true if at least 1 copy issued
string issuedTo[MAX_BOOKS]; // name of person who has it (simple version)

int count = 0; // actual number of books stored

//  UTILITY 

void printLine()
{
    cout << "-------------------------------------------" << endl;
}
void printDoubleLine()
{
    cout << "===========================================" << endl;
}

// returns index of book with given ID, -1 if not found
int findBook(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (bookIDs[i] == id)
            return i;
    }
    return -1;
}

// CORE FUNCTIONS 

void addBook()
{
    if (count >= MAX_BOOKS)
    {
        cout << "Cannot add more books! Library is full." << endl;
        return;
    }

    int id;
    cout << "\n--- ADD BOOK ---" << endl;
    cout << "Enter Book ID  : ";
    cin >> id;

    if (findBook(id) != -1)
    {
        cout << "Book with this ID already exists!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Title    : ";
    getline(cin, titles[count]);
    cout << "Enter Author   : ";
    getline(cin, authors[count]);
    cout << "Enter Copies   : ";
    cin >> totalCopies[count];

    bookIDs[count] = id;
    availableCopies[count] = totalCopies[count];
    isIssued[count] = false;
    issuedTo[count] = "";

    count++;
    cout << "Book added successfully!" << endl;
}

void displayBook(int idx)
{
    printLine();
    cout << "Book ID         : " << bookIDs[idx] << endl;
    cout << "Title           : " << titles[idx] << endl;
    cout << "Author          : " << authors[idx] << endl;
    cout << "Total Copies    : " << totalCopies[idx] << endl;
    cout << "Available       : " << availableCopies[idx] << endl;
    cout << "Status          : " << (availableCopies[idx] > 0 ? "AVAILABLE" : "NOT AVAILABLE") << endl;
    printLine();
}

void displayAllBooks()
{
    if (count == 0)
    {
        cout << "No books in library!" << endl;
        return;
    }
    printDoubleLine();
    cout << "          ALL BOOKS IN LIBRARY" << endl;
    printDoubleLine();
    for (int i = 0; i < count; i++)
    {
        displayBook(i);
    }
}

void searchByID()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
    }
    else
    {
        displayBook(idx);
    }
}

void searchByTitle()
{
    cin.ignore();
    string title;
    cout << "Enter Title to search: ";
    getline(cin, title);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (titles[i] == title)
        {
            displayBook(i);
            found = true;
        }
    }
    if (!found)
        cout << "No book found with that title!" << endl;
}

void searchByAuthor()
{
    cin.ignore();
    string author;
    cout << "Enter Author to search: ";
    getline(cin, author);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (authors[i] == author)
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
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter new Title  : ";
    getline(cin, titles[idx]);
    cout << "Enter new Author : ";
    getline(cin, authors[idx]);
    cout << "Enter new Copies : ";
    cin >> totalCopies[idx];

    // keep available copies in sync if total reduced below available
    if (availableCopies[idx] > totalCopies[idx])
    {
        availableCopies[idx] = totalCopies[idx];
    }

    cout << "Book updated successfully!" << endl;
}

void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    if (availableCopies[idx] != totalCopies[idx])
    {
        cout << "Cannot delete! Some copies are currently issued." << endl;
        return;
    }

    // shift all elements after idx, one position left, across ALL arrays
    for (int i = idx; i < count - 1; i++)
    {
        bookIDs[i] = bookIDs[i + 1];
        titles[i] = titles[i + 1];
        authors[i] = authors[i + 1];
        totalCopies[i] = totalCopies[i + 1];
        availableCopies[i] = availableCopies[i + 1];
        isIssued[i] = isIssued[i + 1];
        issuedTo[i] = issuedTo[i + 1];
    }
    count--;

    cout << "Book deleted successfully!" << endl;
}

void issueBook()
{
    int id;
    cout << "\n--- ISSUE BOOK ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    if (availableCopies[idx] <= 0)
    {
        cout << "No copies available right now!" << endl;
        return;
    }

    cin.ignore();
    string person;
    cout << "Issue to (Name): ";
    getline(cin, person);

    availableCopies[idx]--;
    isIssued[idx] = true;
    issuedTo[idx] = person; // simple version: last person who issued

    cout << "Book \"" << titles[idx] << "\" issued to " << person << " successfully!" << endl;
    cout << "Remaining copies: " << availableCopies[idx] << endl;
}

void returnBook()
{
    int id;
    cout << "\n--- RETURN BOOK ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    if (availableCopies[idx] >= totalCopies[idx])
    {
        cout << "All copies are already in the library!" << endl;
        return;
    }

    availableCopies[idx]++;
    if (availableCopies[idx] == totalCopies[idx])
    {
        isIssued[idx] = false;
        issuedTo[idx] = "";
    }

    cout << "Book \"" << titles[idx] << "\" returned successfully!" << endl;
    cout << "Available copies now: " << availableCopies[idx] << endl;
}

void checkAvailability()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    int idx = findBook(id);
    if (idx == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Title     : " << titles[idx] << endl;
    cout << "Available : " << availableCopies[idx] << " / " << totalCopies[idx] << endl;
}

void sortByTitle()
{
    if (count == 0)
    {
        cout << "No books to sort!" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (titles[j] > titles[j + 1])
            {
                swap(bookIDs[j], bookIDs[j + 1]);
                swap(titles[j], titles[j + 1]);
                swap(authors[j], authors[j + 1]);
                swap(totalCopies[j], totalCopies[j + 1]);
                swap(availableCopies[j], availableCopies[j + 1]);
                swap(isIssued[j], isIssued[j + 1]);
                swap(issuedTo[j], issuedTo[j + 1]);
            }
        }
    }
    cout << "Books sorted by title (A-Z):" << endl;
    displayAllBooks();
}

void availableBooksReport()
{
    if (count == 0)
    {
        cout << "No books in library!" << endl;
        return;
    }
    cout << "\n--- AVAILABLE BOOKS ---" << endl;
    bool any = false;
    for (int i = 0; i < count; i++)
    {
        if (availableCopies[i] > 0)
        {
            any = true;
            cout << bookIDs[i] << " | " << titles[i]
                 << " | Available: " << availableCopies[i] << endl;
        }
    }
    if (!any)
        cout << "No books currently available." << endl;
}

void issuedBooksReport()
{
    if (count == 0)
    {
        cout << "No books in library!" << endl;
        return;
    }
    cout << "\n--- ISSUED BOOKS ---" << endl;
    bool any = false;
    for (int i = 0; i < count; i++)
    {
        if (isIssued[i])
        {
            any = true;
            cout << bookIDs[i] << " | " << titles[i]
                 << " | Issued to: " << issuedTo[i] << endl;
        }
    }
    if (!any)
        cout << "No books currently issued." << endl;
}

//  MAIN MENU 

void showMenu()
{
    printDoubleLine();
    cout << "          MINI LIBRARY SYSTEM" << endl;
    printDoubleLine();
    cout << "1.  Add Book" << endl;
    cout << "2.  Display All Books" << endl;
    cout << "3.  Search by Book ID" << endl;
    cout << "4.  Search by Title" << endl;
    cout << "5.  Search by Author" << endl;
    cout << "6.  Update Book" << endl;
    cout << "7.  Delete Book" << endl;
    cout << "8.  Issue Book" << endl;
    cout << "9.  Return Book" << endl;
    cout << "10. Check Availability" << endl;
    cout << "11. Sort by Title" << endl;
    cout << "12. Available Books Report" << endl;
    cout << "13. Issued Books Report" << endl;
    cout << "0.  Exit" << endl;
    printDoubleLine();
}

int main()
{
    int choice = -1;

    while (choice != 0)
    {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayAllBooks();
            break;
        case 3:
            searchByID();
            break;
        case 4:
            searchByTitle();
            break;
        case 5:
            searchByAuthor();
            break;
        case 6:
            updateBook();
            break;
        case 7:
            deleteBook();
            break;
        case 8:
            issueBook();
            break;
        case 9:
            returnBook();
            break;
        case 10:
            checkAvailability();
            break;
        case 11:
            sortByTitle();
            break;
        case 12:
            availableBooksReport();
            break;
        case 13:
            issuedBooksReport();
            break;
        case 0:
            cout << "Thank you for using Mini Library System!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}