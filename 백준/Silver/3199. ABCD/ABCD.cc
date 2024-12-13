#include <iostream>

using namespace std;
double x, y, z;

int main()
{
    cin >> x >> y >> z;
    if(x != z)
        cout << 0;
    else
    {
        cout << fixed;
        cout.precision(4);
        cout << (x + y + z) * (x + y + z) - (x + y) * (x + y) - z * z;
    }
}