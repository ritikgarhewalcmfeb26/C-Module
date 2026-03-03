/* Q4.1 Write a program that:
Uses new to allocate an array of 5 integers
Takes user input
Prints the values
Deallocates memory using delete[] */

#include <iostream>

using namespace std;

int main() {
    int* arr = new int[5];

    cout << "Enter 5 integers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
