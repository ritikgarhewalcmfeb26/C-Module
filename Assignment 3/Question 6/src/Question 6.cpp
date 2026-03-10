/*Q6. Create a Vector class (not std::vector) with:
A dynamic int array
Size variable
Overloaded operator[] to access elements
Overloaded operator() to return sum of all elements
Tasks:
1. Initialize an object using aggregate initialization (ONLY if suitable).
2. Demonstrate:
3. v[2] = 50;
4. cout << v( ); // should compute sum
5. Explain difference between index and function-call operators. */

#include <iostream>
#include <initializer_list>

using namespace std;

class Vector {
private:
    int* data;
    int size;

public:
    Vector(initializer_list<int> initList) {
        size = initList.size();
        data = new int[size];
        int i = 0;
        for (int val : initList) {
            data[i++] = val;
        }
    }

    ~Vector() {
        delete[] data;
    }

    int& operator[](int index) {
        return data[index];
    }

    int operator()() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }
};

int main() {
    cout << "Task 1: Initialization \n";
    Vector v = {10, 20, 30, 40, 50};

    cout << "Task 2 & 4: Initial Sum\n";
    cout << "Sum before modification: " << v() << "\n";

    cout << "Task 3: Modifying v[2] \n";
    v[2] = 50;
    cout << "Set v[2] = 50\n";

    cout << "Task 4: New Sum \n";
    cout << "Sum after modification: " << v() << "\n";

    return 0;
}
