/*Q2. Create a class Student with:
 roll, name, marks
 Parameterized constructor
 Destructor that prints "Destroying student …"
Tasks:
1. Create an array of 3 Student objects.
2. Write all student details to a file "students.txt".
3. Read the file again and print contents.
4. Explain constructor/destructor call sequence for array of objects.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    Student(int r, string n, float m) : roll(r), name(n), marks(m) {
        cout << "Constructing student " << name << "...\n";
    }

    ~Student() {
        cout << "Destroying student " << name << "...\n";
    }
};

int main() {
    cout << " Task 1: Create array of 3 Student objects \n";
    Student arr[3] = {
        Student(1, "Ritik", 85.5),
        Student(2, "Varun", 92.0),
        Student(3, "Rahul", 78.5)
    };

    cout << "\n--- Task 2: Writing to students.txt ---\n";
    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 3; i++) {
            outFile << arr[i].roll << " " << arr[i].name << " " << arr[i].marks << "\n";
        }
        outFile.close();
        cout << "Data successfully written to file.\n";
    }

    cout << "\nTask 3: Reading from students.txt \n";
    ifstream inFile("students.txt");
    if (inFile.is_open()) {
        int r;
        string n;
        float m;
        while (inFile >> r >> n >> m) {
            cout << "Roll: " << r << " | Name: " << n << " | Marks: " << m << "\n";
        }
        inFile.close();
    }

    cout << "\n Exiting main (Destructors will trigger now) \n";
    return 0;
}
