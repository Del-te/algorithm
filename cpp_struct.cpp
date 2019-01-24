#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x = 0, int y = 0):x(x),y(y){}
};

Point operator + (const Point &A, const Point &B)
{
    return Point(A.x + B.x, A.y + B.y);
}

ostream& operator << (ostream &out, const Point &P)
{
    out << '(' << P.x << ',' << P.y << ')' << ' ';
    return out;
}
int main()
{
    Point A(1, 1);
    Point B(2, 2);
    cout << A + B << endl;  
    system("pause");
    return 0;
}
