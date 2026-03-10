/* Q5. Create a class Number with:
 Private int value
 A friend function to compare two objects (operator>)
 A friend class Inspector that can read private data
 Overload:
o Pre-increment ++n
o Post-increment n++
o Assignment operator =
Tasks:
1. Show difference between pre & post increment.
2. Use Inspector to print private members.
3. Compare objects using friend function. */

#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    Number& operator++() {
        value += 1;
        return *this;
    }

    Number operator++(int) {
        Number temp = *this;
        value += 1;
        return temp;
    }

    Number& operator=(const Number& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    friend bool operator>(const Number& n1, const Number& n2);

    friend class Inspector;
};

bool operator>(const Number& n1, const Number& n2) {
    return n1.value > n2.value;
}

class Inspector {
public:
    void printValue(const Number& n) {
        cout << "Inspector reading private value: " << n.value << "\n";
    }
};

int main() {
    Number n1(5);
    Number n2(10);
    Inspector insp;

    cout << "Task 1: Pre-increment vs Post-increment\n";

    Number n3 = ++n1;
    cout << "After ++n1 (pre-increment):\n";
    cout << "n1: "; insp.printValue(n1);
    cout << "n3: "; insp.printValue(n3);

    Number n4 = n2++;
    cout << "\nAfter n2++ (post-increment):\n";
    cout << "n2: "; insp.printValue(n2);
    cout << "n4: "; insp.printValue(n4);

    cout << "\nTesting Assignment Operator\n";
    Number n5;
    n5 = n1;
    cout << "After n5 = n1:\n";
    cout << "n5: "; insp.printValue(n5);

    cout << "\nTask 2: Inspector usage is demonstrated above\n";

    cout << "\nTask 3: Compare objects using friend function\n";
    if (n2 > n1) {
        cout << "n2 is greater than n1\n";
    } else {
        cout << "n2 is NOT greater than n1\n";
    }

    return 0;
}
