/*Q2.1 Write three functions:
void swapByValue(int a, int b);
void swapByAddress(int *a, int *b);
void swapByReference(int &a, int &b);*/

#include <iostream>

using namespace std;

void swapByVal(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByAdd(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Original values: x = " << x << ", y = " << y << endl<<endl;

    swapByVal(x, y);
    cout << "After swapByValue: x = " << x << ", y = " << y << endl;

    swapByAdd(&x, &y);
    cout << "After swapByAddress: x = " << x << ", y = " << y << endl;

    swapByRef(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;

    return 0;
}
