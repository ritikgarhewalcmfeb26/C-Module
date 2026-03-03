/* Q5.1 Create a class Student with:
rollNo
name
marks
Write the following:
Default constructor
Parameterized constructor
Constructor that uses this-> pointer
A function to print student details
Create:
One object using default constructor
Two objects using parameterized constructor */
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:

    Student() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0f;
    }


    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }


    Student(int rollNo, string name, float marks, bool) {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;
    }


    void display() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl<<endl;

    }
};

int main() {

    Student student1;
    cout << "Student 1 (Default):" << endl;
    student1.display();


    Student student2(101, "Ritik Garhewal", 88.5f);
    cout << "Student 2 (Parameterized):" << endl;
    student2.display();

    Student student3(102, "Varun Garhewal", 92.0f);
    cout << "Student 3 (Parameterized):" << endl;
    student3.display();

    return 0;
}
