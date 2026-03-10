/*Q3. Create a Matrix class using dynamic 2D allocation.
Implement the following:
 operator>> to input matrix
 operator<< to display matrix
 operator+ for matrix addition
 operator== to check equality
Tasks:
1. Create two matrices using cin >> m1 >> m2;
2. Add them: m3 = m1 + m2;
3. Compare matrices using if(m1 == m2)
4. Deallocate memory in destructor.
 */

#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

    void allocate() {
        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
            }
        } else {
            data = nullptr;
        }
    }

    void deallocate() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        allocate();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocate();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocate();
            rows = other.rows;
            cols = other.cols;
            allocate();
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        deallocate();
    }

    friend istream& operator>>(istream& is, Matrix& m) {
        m.deallocate();
        is >> m.rows >> m.cols;
        m.allocate();
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                is >> m.data[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrix dimensions do not match for addition.\n";
            return Matrix();
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Matrix m1, m2, m3;

    cout << "Task 1: Create two matrices\n";
    cout << "Format: [rows] [cols] [element1] [element2] ...\n";
    cout << "Enter data for m1 and m2 sequentially:\n";
    cin >> m1 >> m2;

    cout << "\nTask 2: Add matrices\n";
    m3 = m1 + m2;
    cout << "Result of m1 + m2:\n" << m3;

    cout << "Task 3: Compare matrices\n";
    if (m1 == m2) {
        cout << "m1 and m2 are equal.\n";
    } else {
        cout << "m1 and m2 are NOT equal.\n";
    }

    cout << "\nTask 4: Deallocate memory\n";
    cout << "Destructors will automatically clean up m1, m2, and m3 dynamically allocated memory upon exit.\n";

    return 0;
}
