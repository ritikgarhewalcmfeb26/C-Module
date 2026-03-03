/* Q1. Create a class called Student with the following private data members:
1. name (string):to store the name of the student.
2. rollNumber(int):to store the rollnumber of the student.
3. marks(float): to store the marks obtained by the student.
4. grade(char):to store the grade calculated based on the marks.
Implement getter and setter member functions for each data member
Create a member function calculateGrade() that calculates the grade based on the following
grading scale:
A: 90-100
B: 80-89
C: 70-79
D: 60-69
F: Below 60
Implement a menu-driven program in the main() function with the following options:
1. Accept Information
2. Display information
3. Calculate Grade
4. Exit the program. */

#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;
    char grade;

public:
    Student() : name(""), rollNumber(0), marks(0.0), grade(' ') {}

    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    float getMarks() const { return marks; }
    char getGrade() const { return grade; }

    void setName(const string& n) { name = n; }
    void setRollNumber(int r) { rollNumber = r; }
    void setMarks(float m) { marks = m; }
    void setGrade(char g) { grade = g; }

    void calculateGrade() {
        if (marks >= 90 && marks <= 100) {
            grade = 'A';
        } else if (marks >= 80 && marks < 90) {
            grade = 'B';
        } else if (marks >= 70 && marks < 80) {
            grade = 'C';
        } else if (marks >= 60 && marks < 70) {
            grade = 'D';
        } else if (marks >= 0 && marks < 60) {
            grade = 'F';
        } else {
            cout << "Invalid. Please enter a value b/w 0-100." << endl;
            grade = 'X';
        }
    }

    void displayInformation() const {
        if (rollNumber == 0) {
            cout << "No student info has been entered." << endl;
            return;
        }
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        if (grade == 'X' || grade == ' ') {
             cout << "Grade: Invalid marks." << endl;
        } else {
            cout << "Grade: " << grade << endl;
        }
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Accept Information" << endl;
        cout << "2. Display Information" << endl;
        cout << "3. Calculate Grade" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            while (cin.get() != '\n');
        }

        switch (choice) {
            case 1: {
                string n;
                int r;
                float m;

                cout << "Enter Student Name: ";
                while (cin.get() != '\n');
                getline(cin, n);
                s.setName(n);

                cout << "Enter Roll Number: ";
                while (!(cin >> r)) {
                    cout << "Invalid input. Please enter a number: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                s.setRollNumber(r);

                cout << "Enter Marks: ";
                 while (!(cin >> m) || m < 0 || m > 100) {
                    cout << "Invalid input. Please enter a number between 0 and 100: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                s.setMarks(m);
                s.setGrade(' ');
                cout << "Information accepted successfully!" << endl;
                break;
            }
            case 2:
                cout << "\n--- Student Details ---" << endl;
                s.displayInformation();
                break;
            case 3:
                s.calculateGrade();
                if (s.getGrade() != 'X' && s.getGrade() != ' ') {
                   cout << "Grade calculated successfully!" << endl;
                }
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
