/*Q4. Write a program to divide two integers.
Requirements:
1. Throw a custom exception DivideByZero when denominator = 0.
2. Use nested try-catch where:
o Inner catch prints "Inside inner catch"
o Rethrows the exception
o Outer catch prints "Handled in outer catch"
3. Use an exception specification list on a function that may throw only DivideByZero. */


#include <iostream>

using namespace std;

class DivideByZero : public exception {
public:
    const char* what() const throw() {
        return "Division by zero attempted.";
    }
};

double divide(int numerator, int denominator) throw(DivideByZero) {
    if (denominator == 0) {
        throw DivideByZero();
    }
    return (double)numerator / denominator;
}

int main() {
    int num = 20;
    int den = 0;

    try {
        try {
            cout << "Attempting to divide " << num << " by " << den << "\n";
            double result = divide(num, den);
            cout << "Result: " << result << "\n";
        } catch (DivideByZero& e) {
            cout << "Inside inner catch\n";
            throw;
        }
    } catch (DivideByZero& e) {
        cout << "Handled in outer catch\n";
        cout << "Error details: " << e.what() << "\n";
    }

    return 0;
}
