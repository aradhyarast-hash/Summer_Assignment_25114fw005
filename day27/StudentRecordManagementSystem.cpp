#include <iostream>
using namespace std;
// create student record management system


struct studentRecord {
private:
    string name;
    int rollnum;
public:
    int age;
    string course;
    float marks;

    void addStudent(string n, int rn, int a, string c, float m){
        name = n;
        rollnum = rn;
        age = a;
        course = c;
        marks = m;
    }
    
    void displayStudent(studentRecord s[], int count, int rn){
        bool found = false;
        for(int i = 0; i <  count; i++){
            if(s[i].rollnum == rn){
                cout <<"the record of student : "<< endl;
                cout << "---------------------------------"<< endl;
                found = true;
                cout << "name: "<< s[i].name << endl;
                cout << "rollnum: "<< s[i].rollnum << endl;
                cout << "age: "<< s[i].age << endl;
                cout << "course: "<< s[i].course << endl;
                cout << "marks: "<< s[i].marks << endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;
    }
    
    void display(studentRecord students[], int count){
        
        for(int i = 0; i < count; i++){
            cout << "name : "<< students[i].name << endl;
            cout << "rollnumber : "<< students[i].rollnum << endl;
            cout << "age : "<< students[i].age << endl;
            cout << "course : "<< students[i].course << endl;
            cout << "marks : "<< students[i].marks << endl;
            cout << "---------------------------"<< endl;
        }
    }
    void searchStudent(int rn, studentRecord student[], int count){
        bool found = false;
        for(int i = 0; i < count; i++){
            if(student[i].rollnum == rn){
                found = true;
                cout << "record found!"<< endl;
                cout << "-------------------"<< endl;
                cout << "name: "<< student[i].name<< endl;
                cout << "rollnum: "<< student[i].rollnum<< endl;
                cout << "age: "<< student[i].age<< endl;
                cout << "course: "<< student[i].course<< endl;
                cout << "marks: "<< student[i].marks<< endl;
                break;
            }
        }
        if(!found) cout << "Record Not Found!"<< endl;
    }
    
    void updateStudent(studentRecord s[], int count, int rn){
        bool found = false;
        string n, c;
        int a;
        float m;
        cout << "enter the name: ";
        cin >> n;
        cout << "enter the age: ";
        cin >> a;
        cout << "enter the course: ";
        cin >> c;
        cout << "enter the marks: ";
        cin >> m;
        for(int i = 0; i < count; i++){
            if(s[i].rollnum == rn){
                found = true;
                s[i].name = n;
                s[i].age = a;
                s[i].course = c;
                s[i].marks = m;
                displayStudent(s, count, rn);
                cout << "----------------------------------"<< endl;
                cout << "student updated!"<< endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;
    }
    
    void delStudent(studentRecord s[], int rn, int &count){
        bool found = false;
        for(int i = 0; i < count; i++){
            if(s[i].rollnum == rn){
                found = true;
                for(int j = i; j < count; j++){
                    s[j] = s[j+1];
                }
                count--;
                cout << "Record Deleted!"<< endl;
                break;
            }
        }
        if(!found) cout << "record not found!"<< endl;
    }
    
    void sortMarks(studentRecord s[], int count){
        for(int i = 0; i < count-1; i++){
            for(int j = 0; j < count-i-1; j++){
                if(s[j].marks < s[j+1].marks){
                    swap(s[j], s[j+1]);
                }
            }
        }
        cout << "the sorted records are: "<< endl << "--------------------------------------"<< endl;
        display(s, count);
    }
    
};
int main()
{
    cout << "========== STUDENT RECORD MANAGEMENT ==========" << endl;
    
    // 1. Add Student
    // 2. display a record
    // 3. Display All Students record
    // 4. Search Student
    // 5. Update Student
    // 6. Delete Student
    // 7. Sort and display Students by Marks
    // 8. Exit

    studentRecord s1[100];
    int choice = 0;
    int count = 0;
    while(choice != 8){
        cout << "enter the choice number : ";
        cin >> choice; 
        string name, course;
        int roll = 0, age = 0;
        float mark;
        int r;

        switch(choice){
            case 1:
                cout << "enter the name : ";
                cin.ignore();
                getline(cin, name);

                cout << "enter the roll : ";
                cin >> roll;

                cout << "enter the age : ";
                cin >> age;
                
                cout << "enter the course : ";
                cin.ignore();
                getline(cin, course);

                cout << "enter the marks : ";
                cin >> mark;

                s1[count].addStudent(name, roll, age, course, mark);
                count++;
                cout << "student added!" << endl;
                break;

            case 2:
                cout <<"enter the roll number to display: ";
                cin >> r;
                s1[count].displayStudent(s1, count, r);
                break;

            case 3:
                cout << "here are the records: "<< endl;
                cout << "--------------------------"<< endl;
                s1[count].display(s1, count);
                break;
            
            case 4:
                cout << "enter the roll number to search: ";
                cin >> r;
                s1[count].searchStudent(r, s1, count);
                break;

            case 5:
                cout << "enter the roll number to update: ";
                cin >> r;
                s1[count].updateStudent(s1, count, r);
                break;

            case 6:
                cout << "enter the roll number to delete: ";
                cin >> r;
                s1[count].delStudent(s1, r, count);
                break;

            case 7:
                s1[count].sortMarks(s1, count);
                break;

            case 8:
                cout << "thank you!"<< endl;
                exit(0);
        }
    }
    return 0;
}