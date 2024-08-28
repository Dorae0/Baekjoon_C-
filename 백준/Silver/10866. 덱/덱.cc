#include <iostream>
#include <deque>
#include <string>

using namespace std;
int n, x;
string s;
deque<int> dq;

void Execute();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        Execute();
    return 0;
}

void Execute()
{
    cin >> s;
    if(s == "push_front")
    {
        cin >> x;
        dq.push_front(x);
    }
    else if(s == "push_back")
    {
        cin >> x;
        dq.push_back(x);
    }
    else if(s == "pop_front")
    {
        if(dq.empty())
            cout << -1 << endl;
        else
        {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }
    else if(s == "pop_back")
    {
        if(dq.empty())
            cout << -1 << endl;
        else
        {
            cout << dq.back() << endl;
            dq.pop_back();
        }
    }
    else if(s == "size")
    {
        cout << dq.size() << endl;
    }
    else if(s == "empty")
    {
        cout << dq.empty() << endl;
    }
    else if(s == "front")
    {
        if(dq.empty())
            cout << - 1 << endl;
        else
            cout << dq.front() << endl;
    }
    else if(s == "back")
    {
        if(dq.empty())
            cout << - 1 << endl;
        else
            cout << dq.back() << endl;
    }
}