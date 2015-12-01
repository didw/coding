//https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/rectangle-area

#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width, height;
public:
    Rectangle() {}
    void Display() {
        cout << width << " " << height << endl;
    }
        
};

class RectangleArea : public Rectangle{
public:
    RectangleArea() {}
    void Input() {
        cin >> width;
        cin >> height;
    }
    void Display() {
        cout << width*height;
    }
};