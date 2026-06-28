// EMPLYOYEE MANAGEMENT SYSTEM

#include <iostream>
using namespace std;
// 1. add employee
// 2. display 1 employee
// 3. display all employee
// 4. delete employee
// 5. update employee
// 6. search employee
// 7. exit

struct employee
{
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

    void displayEmployee(employee emp[], int id, int count){
        if(count == 0) {
            cout <<"No record found!"<< endl;
            return;
        }
        bool found = false;
        for(int i = 0;i < count; i++){
            if(emp[i].empID == id){
                // display
                found = true;
                cout <<"here is the record : "<< endl;
                cout << "----------------------"<< endl;
                cout << "empId: "<< emp[i].empID <<endl;
                cout << "name: "<< emp[i].name <<endl;
                cout << "department: "<< emp[i].department <<endl;
                cout << "experience: "<< emp[i].experience <<endl;
                cout << "salary: "<< emp[i].salary <<endl;
                cout << endl<< endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;

    }
    
    
    void display(employee emp[], int count){
        if(count == 0) {
            cout <<"No record found!"<< endl;
            return;
        }
        cout <<"here is the record : "<< endl;
        cout << "----------------------"<< endl;
        for(int i = 0; i < count; i++){
            cout << "empId: "<< emp[i].empID <<endl;
            cout << "name: "<< emp[i].name <<endl;
            cout << "department: "<< emp[i].department <<endl;
            cout << "experience: "<< emp[i].experience <<endl;
            cout << "salary: "<< emp[i].salary <<endl;
            cout << "------------------------------------";
            cout << endl;
        }
    }
    void deleteEmpolyee(employee emp[], int count, int id){
        if(count == 0) {
            cout <<"No record found!"<< endl;
            return;
        }
        bool found = false;
        for(int i = 0; i < count; i++){
            if(emp[i].empID == id){
                found =true;
                for(int j = i; j < count; j++){
                    emp[j] = emp[j+1];
                }
                count--;
                cout << "Record Deleted!"<< endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;
    }


    void updateEmployee(employee emp[], int count, int id){
        if(count == 0) {
            cout <<"No record found!"<< endl;
            return;
        }
        bool found = false;
        for(int i = 0; i < count; i++){
            if(emp[i].empID == id){
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
        if(!found) cout << "record not found!"<< endl;
    }

    void searchEmployeeByID(employee emp[], int count, int id){
        if(count == 0) {
            cout <<"No record found!"<< endl;
            return;
        }
        bool found = false;
        for(int i = 0; i < count; i++){
            if(emp[i].empID == id){
                found = true;
                cout << "here is the record"<< endl<<"---------------------------------"<< endl;
                cout <<"name: "<< emp[i].name<< endl;
                cout <<"empID: "<< emp[i].empID<< endl;
                cout <<"department: "<< emp[i].department<< endl;
                cout <<"experience: "<< emp[i].experience<< endl;
                cout <<"salary: "<< emp[i].salary<< endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;
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
         << "2. display 1 employee " << endl
         << "3. display all employee" << endl
         << "4. delete employee" << endl
         << "5. update employee" << endl
         << "6. search employee" << endl
         << "7. exit" << endl;

    int choice = 0;
    while (choice != 7)
    {
        cout << "enter your choice : ";
        cin >>  choice;
        switch (choice)
        {
        case 1:
            emp[count].addEmployee();
            count++;
            break;
        case 2:
            cout << "enter the employee ID to display: ";
            cin >> ID;
            emp[count].displayEmployee(emp, ID, count);
            break;
        case 3:
            emp[count].display(emp, count);
            break;
        case 4:
            cout<< "enter the employee ID to delete : ";
            cin >> ID;
            emp[count].deleteEmpolyee(emp, count, ID);
            break;
        
        case 5:
            cout<< "enter the employee ID to update : ";
            cin >> ID;
            emp[count].updateEmployee(emp, count, ID);
            break;
            
        case 6:
        
            cout<< "enter the employee ID to search : ";
            cin >> ID;
            emp[count].searchEmployeeByID(emp, count, ID);
            break;

        case 7:
            cout << "===================================="<< endl;
            cout << "THANK YOU!"<< endl;
        }
    }
    return 0;
}