/*
 * C plus plus learning.
 * Question: How to overloading << for a class/object.
 */
#include <iostream>
#include <cstdlib>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point( int x, int y );
    ~Point();
    // FIXME: this overloading does not work
    friend ostream& operator<<(ostream &output, const Point &thiz);
};

Point::Point() {}
Point::Point(int ax, int ay) {
    x = ax;
    y = ay;
}
Point::~Point() {}

ostream& operator<<(ostream &output, const Point &thiz) {
    output << "(" << thiz.x << ", " << thiz.y << ")";
    return output;
}

int main() {
    Point a( 3, 4 );
    cout << a << endl;
    system("PAUSE");
    return 0;
}
