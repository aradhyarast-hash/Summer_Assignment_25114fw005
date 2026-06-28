#include <iostream>
using namespace std;
// 1. Add Employee
// 2. Display All Employees
// 3. Search Employee
// 4. Update Employee
// 5. Delete Employee
// 6. Calculate Salary
// 7. Sort by Salary
// 8. Sort by Name
// 9. Highest Paid Employee
// 10. Lowest Paid Employee
// 11. Display Department-wise Employees
// 12. Exit

struct employee
{
public:
    string name;
    int empID;
    string department;
    float experience;
    int salary;

    void addEmployee()
    {
        string n, d;
        int ID, s;
        float exp;
        cout << "enter the name of employee : ";
        cin >> n;
        cout << "enter the empID of employee : ";
        cin >> ID;
        cout << "enter the department of employee : ";
        cin >> d;
        cout << "enter the experience of employee : ";
        cin >> exp;
        cout << "enter the salary of employee : ";
        cin >> s;

        name = n;
        empID = ID;
        department = d;
        experience = exp;
        salary = s;
        cout << "record added!" << endl;
    }

    void display(employee emp[], int count)
    {
        if (count == 0)
        {
            cout << "No record found!" << endl;
            return;
        }
        cout << "here is the record : " << endl;
        cout << "----------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "empId: " << emp[i].empID << endl;
            cout << "name: " << emp[i].name << endl;
            cout << "department: " << emp[i].department << endl;
            cout << "experience: " << emp[i].experience << endl;
            cout << "salary: " << emp[i].salary << endl;
            cout << "------------------------------------";
            cout << endl;
        }
    }

    void deleteEmpolyee(employee emp[], int count, int id)
    {
        if (count == 0)
        {
            cout << "No record found!" << endl;
            return;
        }
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (emp[i].empID == id)
            {
                found = true;
                for (int j = i; j < count; j++)
                {
                    emp[j] = emp[j + 1];
                }
                count--;
                cout << "Record Deleted!" << endl;
                break;
            }
        }
        if (!found)
            cout << "record not found!" << endl;
    }

    void updateEmployee(employee emp[], int count, int id)
    {
        if (count == 0)
        {
            cout << "No record found!" << endl;
            return;
        }
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (emp[i].empID == id)
            {
                found = true;
                cout << "enter the name : ";
                cin >> name;
                cout << "enter the department : ";
                cin >> department;
                cout << "enter the experience : ";
                cin >> experience;
                cout << "enter the salary : ";
                cin >> salary;
                emp[i].name = name;
                emp[i].department = department;
                emp[i].experience = experience;
                emp[i].salary = salary;
                break;
            }
        }
        if (!found)
            cout << "record not found!" << endl;
    }

    void searchEmployeeByID(employee emp[], int count, int id)
    {
        if (count == 0)
        {
            cout << "No record found!" << endl;
            return;
        }
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (emp[i].empID == id)
            {
                found = true;
                cout << "here is the record" << endl
                     << "---------------------------------" << endl;
                cout << "name: " << emp[i].name << endl;
                cout << "empID: " << emp[i].empID << endl;
                cout << "department: " << emp[i].department << endl;
                cout << "experience: " << emp[i].experience << endl;
                cout << "salary: " << emp[i].salary << endl;
                break;
            }
        }
        if (!found)
            cout << "record not found!" << endl;
    }

    void calculateSalary(employee emp[], int count, int id)
    {
        if (count == 0)
        {
            cout << "no record found!";
            return;
        }
        // HRA -> 20%(HOUSE RENT ALLOWANCE)
        // DA -> 10% (dearness allowance)
        // bonus -> (fixed) 3000rs/-
        // overtime -> 300rs/hour.
        float hra = 0.2, da = 0.1;
        int bonus = 3000, price = 300;
        bool found = false;
        float ot = 0;
        float tax = 0.05;
        int amount = 0;

        for (int i = 0; i < count; i++)
        {
            if (emp[i].empID == id)
            {
                found = true;
                cout << "enter overtime hours : ";
                cin >> ot;
                emp[i].salary = emp[i].salary + emp[i].salary * hra + emp[i].salary * da + bonus + ot * price;
                amount = emp[i].salary * tax;
                cout << "salary: " << emp[i].salary - amount << endl;

                break;
            }
        }
        if (!found)
            cout << "record not found!" << endl;
    }
};
int main()
{

    employee emp[100];
    string n, d;
    int ID, s;
    float exp;
    int count = 0;
    cout << "1.add employee" << endl
         << "2. display all employee" << endl
         << "3. delete employee" << endl
         << "4. update employee" << endl
         << "5. search employee" << endl
         << "6. calculate salary" << endl
         << "7. exit" << endl;

    int choice = 0;
    while (choice != 7)
    {
        cout << "enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            emp[count].addEmployee();
            count++;
            break;
        
        case 2:
            emp[count].display(emp, count);
            break;
        case 3:
            cout << "enter the employee ID to delete : ";
            cin >> ID;
            emp[count].deleteEmpolyee(emp, count, ID);
            break;

        case 4:
            cout << "enter the employee ID to update : ";
            cin >> ID;
            emp[count].updateEmployee(emp, count, ID);
            break;

        case 5:

            cout << "enter the employee ID to search : ";
            cin >> ID;
            emp[count].searchEmployeeByID(emp, count, ID);
            break;

        case 6:
            cout << "enter the employee ID to calculate the salary : ";
            cin >> ID;
            emp[count].calculateSalary(emp, count, ID);
            break;

        case 7:
            cout << "====================================" << endl;
            cout << "THANK YOU!" << endl;
            break;
        }
    }
    return 0;
}