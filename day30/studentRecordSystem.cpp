
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

//  PARALLEL ARRAYS 
string names[MAX_STUDENTS];
int rollNumbers[MAX_STUDENTS];
int ages[MAX_STUDENTS];
string courses[MAX_STUDENTS];
float marks[MAX_STUDENTS];

int count = 0; // actual number of students stored

//  UTILITY 

void printLine()
{
    cout << "-------------------------------------------" << endl;
}
void printDoubleLine()
{
    cout << "===========================================" << endl;
}

// returns index of student with given roll number, -1 if not found
int findStudent(int roll)
{
    for (int i = 0; i < count; i++)
    {
        if (rollNumbers[i] == roll)
            return i;
    }
    return -1;
}

// ================= CORE FUNCTIONS ====================

void addStudent()
{
    if (count >= MAX_STUDENTS)
    {
        cout << "Cannot add more students! Record is full." << endl;
        return;
    }

    int roll;
    cout << "\n--- ADD STUDENT ---" << endl;
    cout << "Enter Roll Number: ";
    cin >> roll;

    if (findStudent(roll) != -1)
    {
        cout << "Student with this roll number already exists!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Name : ";
    getline(cin, names[count]);
    cout << "Enter Age : ";
    cin >> ages[count];
    cin.ignore();
    cout << "Enter Course : ";
    getline(cin, courses[count]);
    cout << "Enter Marks : ";
    cin >> marks[count];

    rollNumbers[count] = roll;
    count++;

    cout << "Student added successfully!" << endl;
}

void displayStudent(int idx)
{
    printLine();
    cout << "Roll Number : " << rollNumbers[idx] << endl;
    cout << "Name        : " << names[idx] << endl;
    cout << "Age         : " << ages[idx] << endl;
    cout << "Course      : " << courses[idx] << endl;
    cout << "Marks       : " << marks[idx] << endl;
    printLine();
}

void displayAllStudents()
{
    if (count == 0)
    {
        cout << "No student records found!" << endl;
        return;
    }
    printDoubleLine();
    cout << "          ALL STUDENT RECORDS" << endl;
    printDoubleLine();
    for (int i = 0; i < count; i++)
    {
        displayStudent(i);
    }
}

void searchStudent()
{
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;
    int idx = findStudent(roll);
    if (idx == -1)
    {
        cout << "Student not found!" << endl;
    }
    else
    {
        cout << "Student found!" << endl;
        displayStudent(idx);
    }
}

void searchByName()
{
    cin.ignore();
    string name;
    cout << "Enter Name to search: ";
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (names[i] == name)
        {
            displayStudent(i);
            found = true;
        }
    }
    if (!found)
        cout << "No student found with that name!" << endl;
}

void updateStudent()
{
    int roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;
    int idx = findStudent(roll);
    if (idx == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter new Name   : ";
    getline(cin, names[idx]);
    cout << "Enter new Age    : ";
    cin >> ages[idx];
    cin.ignore();
    cout << "Enter new Course : ";
    getline(cin, courses[idx]);
    cout << "Enter new Marks  : ";
    cin >> marks[idx];

    cout << "Student record updated successfully!" << endl;
}

void deleteStudent()
{
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;
    int idx = findStudent(roll);
    if (idx == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    // shift all elements after idx, one position left, across ALL arrays
    for (int i = idx; i < count - 1; i++)
    {
        names[i] = names[i + 1];
        rollNumbers[i] = rollNumbers[i + 1];
        ages[i] = ages[i + 1];
        courses[i] = courses[i + 1];
        marks[i] = marks[i + 1];
    }
    count--;

    cout << "Student record deleted successfully!" << endl;
}

void sortByMarks()
{
    if (count == 0)
    {
        cout << "No records to sort!" << endl;
        return;
    }
    // bubble sort descending by marks — swap across all parallel arrays together
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {
                swap(names[j], names[j + 1]);
                swap(rollNumbers[j], rollNumbers[j + 1]);
                swap(ages[j], ages[j + 1]);
                swap(courses[j], courses[j + 1]);
                swap(marks[j], marks[j + 1]);
            }
        }
    }
    cout << "Students sorted by marks (highest first):" << endl;
    displayAllStudents();
}

void sortByName()
{
    if (count == 0)
    {
        cout << "No records to sort!" << endl;
        return;
    }
    // bubble sort alphabetically by name
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (names[j] > names[j + 1])
            {
                swap(names[j], names[j + 1]);
                swap(rollNumbers[j], rollNumbers[j + 1]);
                swap(ages[j], ages[j + 1]);
                swap(courses[j], courses[j + 1]);
                swap(marks[j], marks[j + 1]);
            }
        }
    }
    cout << "Students sorted by name (A-Z):" << endl;
    displayAllStudents();
}

void averageMarks()
{
    if (count == 0)
    {
        cout << "No records found!" << endl;
        return;
    }
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += marks[i];
    }
    cout << "Average Marks of all students: " << (total / count) << endl;
}

void topStudent()
{
    if (count == 0)
    {
        cout << "No records found!" << endl;
        return;
    }
    int topIdx = 0;
    for (int i = 1; i < count; i++)
    {
        if (marks[i] > marks[topIdx])
            topIdx = i;
    }
    cout << "Top Student:" << endl;
    displayStudent(topIdx);
}

// MAIN MENU

void showMenu()
{
    printDoubleLine();
    cout << "      STUDENT RECORD SYSTEM" << endl;
    printDoubleLine();
    cout << "1.  Add Student" << endl;
    cout << "2.  Display All Students" << endl;
    cout << "3.  Search by Roll No." << endl;
    cout << "4.  Search by Name" << endl;
    cout << "5.  Update Student" << endl;
    cout << "6.  Delete Student" << endl;
    cout << "7.  Sort by Marks" << endl;
    cout << "8.  Sort by Name" << endl;
    cout << "9.  Average Marks" << endl;
    cout << "10. Top Student" << endl;
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
            addStudent();
            break;
        case 2:
            displayAllStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            updateStudent();
            break;
        case 6:
            deleteStudent();
            break;
        case 7:
            sortByMarks();
            break;
        case 8:
            sortByName();
            break;
        case 9:
            averageMarks();
            break;
        case 10:
            topStudent();
            break;
        case 0:
            cout << "Thank you for using Student Record System!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}