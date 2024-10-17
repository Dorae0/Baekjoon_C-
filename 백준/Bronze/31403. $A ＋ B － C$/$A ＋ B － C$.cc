#include <iostream>
#include <string>

using namespace std;
int a, b, c;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << a + b - c << '\n' << stoi(to_string(a) + to_string(b)) - c;
}