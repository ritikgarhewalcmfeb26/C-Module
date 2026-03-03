/*  Q4.2 Repeat Q4.1 using malloc and free.*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int* arr = (int*)malloc(5 * sizeof(int));

    cout << "Enter 5 integers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    free(arr);

    return 0;
}
