#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s;
stack<char> stck;
void Init();
bool IsOperand(char c);
void CheckOperator(char c);
void Solve();

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
}

bool IsOperand(char c)
{
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}

void CheckOperator(char c)
{
    if(stck.empty())
    {
        stck.push(c);
        return;
    }
    else
    {
        if(c == '+' || c == '-')
        {        
            while(!stck.empty())
            {
                if(stck.top() == '(')
                {
                    stck.push(c);
                    return;
                }
                cout << stck.top();
                stck.pop();
            }
            stck.push(c);
        }
        else if(c == '*' || c == '/')
        {
            while(!stck.empty())
            {
                
                char CurrentFront = stck.top();
                if(CurrentFront == '(')
                {
                    stck.push(c);
                    return;
                }
                if(CurrentFront == '*' || CurrentFront == '/')
                {
                    cout << CurrentFront;
                    stck.pop();
                    stck.push(c);
                    return;
                }
                else
                {
                    stck.push(c);
                    return;
                }
            }
        }
        else if(c == '(')
        {
            stck.push(c);
            return;
        }
        else if(c == ')')
        {
            while(!stck.empty())
            {
                char CurrentFront = stck.top();
                if(CurrentFront == '(')
                {
                    stck.pop();
                    return;
                }
                else
                {
                    cout << CurrentFront;
                    stck.pop();
                }
            }
        }
    }
}

void Solve()
{
    for(int i = 0; i < s.length(); i++)
    {
        char CurrentChar = s[i];
        if(IsOperand(CurrentChar))
            cout << CurrentChar;
        else
            CheckOperator(CurrentChar);
    }
    while(!stck.empty())
    {
        if(stck.top() != '(' && stck.top() != ')')
            cout << stck.top();
        stck.pop();
    }
}