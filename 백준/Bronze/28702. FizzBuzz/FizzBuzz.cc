#include <iostream>

using namespace std;
string s;
int Val;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++)
    {
        cin >> s;
        if(s != "Fizz" && s != "Buzz" && s != "FizzBuzz")
        {
            Val = stoi(s);
            Val += (3 - i);
            break;
        }
    }
    if(Val % 3 == 0)
    {
        if(Val % 5 == 0)
            cout << "FizzBuzz";
        else
            cout << "Fizz";
    }
    else
    {
        if(Val % 5 == 0)
            cout << "Buzz";
        else
            cout << Val;
    }
}