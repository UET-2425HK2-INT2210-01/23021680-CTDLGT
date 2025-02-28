#include <iostream>
using namespace std;\

class Point {

    
    
    public:
    double x;
    double y;
    
    Point(){}
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

class Line {
    public:

    double a;
    double b;

    Line(){}

    Line(Point p1, Point p2) {
        a= (p1.y - p2.y) / (p1.x - p2.x);
        b = p1.y - a*p1.x;
    }

    void Print() {
        cout <<"y=" << a <<",x=" << b << endl;
    }

};

void findIntersection(Line AB, Line CD) {
    if (AB.a == CD.a) {
        cout << (AB.b == CD.b ? "MANY" : "NO") << endl;
    } else {
        double x = (CD.b - AB.b) / (AB.a - CD.a);
        double y = AB.a * x + AB.b;
        cout << x << " " << y << endl;
    }
}


int main() {
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    findIntersection(Line(A, B), Line(C, D));
    return 0;
}