/* Q6.1 Create a class Employee with:
const int employeeId
string name
float salary
Write a constructor using initializer list to initialize all members.
Q6.2 — Add a function to display details. */

#include <iostream>

using namespace std;

class Employee {
private:
    const int employeeId;
    string name;
    float salary;

public:
    Employee(int id, string n, float s) : employeeId(id), name(n), salary(s) {}

    void displayDetails() const {
        cout << "ID: " << employeeId << "\nName: " << name << "\nSalary: " << salary << endl;
    }
};

int main() {
    Employee emp(101, "Ritik Garhewal", 55000.50);
    emp.displayDetails();
    return 0;
}
