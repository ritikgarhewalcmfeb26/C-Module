/* Q4. You are tasked with creating an Employee Payroll Management System in C++. Your
program should allow the user to perform the following tasks through a menu-driven
menu
interface:
1. Add a new employee:
- Create a class Employee with the following private data members:
- int empID (EmployeeID)
ID)
- string empName (Employee
(EmployeeName)
- double empSalary(Employee Salary)
- Include appropriate getter and setter methods for these data members.
- Ensure that the Employee ID is unique for each employee.
2. Calculate the gross salary for an employee:
- Create a member function calculate GrossSalary in the Employee class.
- The gross salary should be calculated based on the following rules:
- If the employee's salaryy is less than or equal to 5000, add a 10% bonus.
- If the employee's salary is greater than 5000 but less than or equal to 10000, add a 15%
bonus.
- If the employee's salary is greater than10000,add a 20% bonus.
- Display the gross salary for the chosen employee.
3. Display the employee details:
- Create a member function displayEmployeeDetails in the Employee class to display
all the details of an employee (ID, Name, Salary, and Gross Salary).
4. Update employee information:
- Allow the user to update the employee's name and salary using setter methods.
5. Exit the program. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double empSalary;

public:
    Employee() : empID(0), empName(""), empSalary(0.0) {}

    int getEmpID() const { return empID; }
    string getEmpName() const { return empName; }
    double getEmpSalary() const { return empSalary; }

    void setEmpID(int id) { empID = id; }
    void setEmpName(string name) { empName = name; }
    void setEmpSalary(double salary) { empSalary = salary; }

    double calculateGrossSalary() const {
        double bonus = 0;
        if (empSalary <= 5000) {
            bonus = empSalary * 0.10;
        } else if (empSalary > 5000 && empSalary <= 10000) {
            bonus = empSalary * 0.15;
        } else {
            bonus = empSalary * 0.20;
        }
        return empSalary + bonus;
    }

    void displayEmployeeDetails() const {
        cout << "ID: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Base Salary: " << empSalary << endl;
        cout << "Gross Salary: " << calculateGrossSalary() << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n--- Employee Payroll Management System ---" << endl;
        cout << "1. Add a new employee" << endl;
        cout << "2. Calculate Gross Salary" << endl;
        cout << "3. Display Employee Details" << endl;
        cout << "4. Update Employee Information" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Invalid input. Enter a number: ";
        }

        switch (choice) {
            case 1: {
                Employee temp;
                int id;
                string name;
                double salary;
                bool exists;

                do {
                    exists = false;
                    cout << "Enter Employee ID: ";
                    cin >> id;
                    for (const auto& e : employees) {
                        if (e.getEmpID() == id) {
                            cout << "ID already exists. Try again." << endl;
                            exists = true;
                            break;
                        }
                    }
                } while (exists);

                temp.setEmpID(id);
                cout << "Enter Name: ";
                while (cin.get() != '\n');
                getline(cin, name);
                temp.setEmpName(name);
                cout << "Enter Salary: ";
                cin >> salary;
                temp.setEmpSalary(salary);

                employees.push_back(temp);
                cout << "Employee added successfully." << endl;
                break;
            }
            case 2: {
                int id;
                bool found = false;
                cout << "Enter Employee ID: ";
                cin >> id;
                for (const auto& e : employees) {
                    if (e.getEmpID() == id) {
                        cout << "Gross Salary for " << e.getEmpName() << ": " << e.calculateGrossSalary() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Employee not found." << endl;
                break;
            }
            case 3: {
                if (employees.empty()) {
                    cout << "No employees to display." << endl;
                } else {
                    for (const auto& e : employees) {
                        e.displayEmployeeDetails();
                    }
                }
                break;
            }
            case 4: {
                int id;
                bool found = false;
                cout << "Enter Employee ID to update: ";
                cin >> id;
                for (auto& e : employees) {
                    if (e.getEmpID() == id) {
                        string name;
                        double salary;
                        cout << "Enter New Name: ";
                        while (cin.get() != '\n');
                        getline(cin, name);
                        cout << "Enter New Salary: ";
                        cin >> salary;
                        e.setEmpName(name);
                        e.setEmpSalary(salary);
                        cout << "Updated successfully." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Employee not found." << endl;
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
