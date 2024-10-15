#include <iostream>
#include <string>

using namespace std;

int n;
string s;

bool Solve();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(Solve())
            cout << "nice" << '\n';
        else
            cout << "not nice" << '\n';
    }
}

bool Solve()
{
    int FrontVal = 0;
    int BackVal = 0;
    FrontVal = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A');
    BackVal = stoi(s.substr(4));
    if(abs(FrontVal - BackVal) <= 100)
        return true;
    else
        return false;
}