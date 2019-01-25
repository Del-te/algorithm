#include <iostream>
using namespace std;

int main()
{
    int x = 8;
    if ((x & (x - 1)) == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    x = 9;
    if ((x & (x - 1)) == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    system("pause");
    return 0;
}
