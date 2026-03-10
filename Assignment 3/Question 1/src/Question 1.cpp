/*Q1. Create a class Employee with:
int id
string name
mutable int accessCount
A const member function display() that increments accessCount
 A user-defined copy constructor (deep copy where applicable)
Show difference between:
o Shallow copy
o Deep copy
o Default copy constructor
o Your user-defined copy constructor
Tasks:
1. Create object e1, call display() multiple times.
2. Create e2 = e1; and prove whether copying was shallow or deep.
3. Explain why display() must be const and why accessCount must be mutable */

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    string name;
    mutable int accessCount;

    Employee(int empId, string empName)
        : id(empId), name(empName), accessCount(0) {}

    Employee(const Employee& other) {
        id = other.id;
        name = other.name;
        accessCount = 0;

        cout << "\nUser-defined copy constructor called for " << name << ".\n";
    }

    void display() const {
        accessCount++;
        cout << "ID: " << id << " | Name: " << name
             << " | Display accessed: " << accessCount << " time(s).\n";
    }
};

int main() {
    cout << " Task 1: Create e1 and call display() \n";
    Employee e1(101, "Ritik");
    e1.display();
    e1.display();
    e1.display();

    cout << "\nTask 2: Create e2 = e1 and prove copy behavior ";
    Employee e2 = e1;
    e2.display();

    cout << "\n Proof of Deep Copy / Independent Objects \n";

    cout << "e1's accessCount: " << e1.accessCount << "\n";
    cout << "e2's accessCount: " << e2.accessCount << "\n";

    cout << "Address of e1's name object: " << (void*)&e1.name << "\n";
    cout << "Address of e2's name object: " << (void*)&e2.name << "\n";

    return 0;
}
