#include <iostream>

using namespace std;

class Box {
private:
    int length;
    int width;
    int height;

public:
    Box() : length(0), width(0), height(0) {}

    Box(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }

    void setDimensions(int length, int width, int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    int volume() {
        return length * width * height;
    }
};

int main() {
    cout << "    Box Class Demonstration    " << endl;

    Box box1(5, 4, 3);
    cout << "Box 1:" << endl;
    cout << "Volume = " << box1.volume() << endl<< endl;


    Box box2;
    box2.setDimensions(10, 8, 5);

    cout << "Box 2:" << endl;
    cout << "Volume = " << box2.volume() << endl<< endl;

    return 0;
}
