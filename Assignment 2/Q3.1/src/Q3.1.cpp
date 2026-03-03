/*Q3.1 Write a program to store an integer value in a variable, then:

Create a pointer pointing to the variable
Create a reference to the same variable
Modify the value using pointer and reference
Print the variable after each change.*/

#include <iostream>

using namespace std;

int main() {
    int num = 10;

    cout << "Initial value: " << num << endl;

    int* ptr = &num;
    int& ref = num;

    *ptr = 50;
    cout << "Value after modifying via pointer: " << num << endl;

    ref = 100;
    cout << "Value after modifying via reference: " << num << endl;

    return 0;
}
