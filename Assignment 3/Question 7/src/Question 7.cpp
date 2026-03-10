/* Q7. Implement your own String class (char pointer) with:
Constructor
Copy constructor
Destructor
Assignment operator
operator+ for concatenation
operator<< / operator>>
Tasks:
1. Input two strings using your class.
2. Concatenate them using s3 = s1 + s2;
3. Print all three strings.
4. Demonstrate memory handling (deep copy) */


#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* val) {
        length = strlen(val);
        str = new char[length + 1];
        strcpy(str, val);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    String operator+(const String& other) const {
        char* tempBuff = new char[length + other.length + 1];
        strcpy(tempBuff, str);
        strcat(tempBuff, other.str);
        String tempString(tempBuff);
        delete[] tempBuff;
        return tempString;
    }

    friend ostream& operator<<(ostream& os, const String& s) {
        os << s.str;
        return os;
    }

    friend istream& operator>>(istream& is, String& s) {
        char buffer[1024];
        is >> buffer;
        s = String(buffer);
        return is;
    }

    void showMemoryAddress() const {
        cout << (void*)str;
    }
};

int main() {
    String s1, s2;

    cout << "Task 1: Input two strings\n";
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << "\nTask 2: Concatenate s3 = s1 + s2\n";
    String s3 = s1 + s2;

    cout << "\nTask 3: Print all three strings\n";
    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n";
    cout << "s3: " << s3 << "\n";

    cout << "\nTask 4: Demonstrate memory handling (Deep Copy)\n";
    String s4 = s1;

    cout << "s1 content: " << s1 << " | Heap Address: ";
    s1.showMemoryAddress();
    cout << "\n";

    cout << "s4 content: " << s4 << " | Heap Address: ";
    s4.showMemoryAddress();
    cout << "\n\nNotice that s1 and s4 have identical content but entirely distinct memory addresses.\n";

    return 0;
}
