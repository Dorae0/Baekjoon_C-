#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
string s, explosive;

stack<char> stringStack;

void Init();
void Explosion();
void ExplosiveCheck();
bool IsFRULA();
void Print();

int main()
{
    Init();
    Explosion();
    Print();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> explosive;
}

void Explosion()
{
    char Key = explosive[explosive.length() - 1];
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == Key)
        {
            stringStack.push(s[i]);
            ExplosiveCheck();
        }
        else
        {
            stringStack.push(s[i]);
        }
    }
}

void ExplosiveCheck()
{
    string checkstring = "";
    if(stringStack.size() < explosive.length())
        return;
    for(int i = 0; i < explosive.length(); i++)
    {
        checkstring.push_back(stringStack.top());
        stringStack.pop();
    }
    reverse(checkstring.begin(), checkstring.end());
    if(explosive == checkstring)
        return;
    else
    {
        for(int i = 0; i < checkstring.length(); i++)
            stringStack.push(checkstring[i]);
    }
}

bool IsFRULA()
{
    if(stringStack.empty()) 
        return true;
    else
        return false;
}

void Print()
{
    string ans = "";
    if(IsFRULA()) 
        cout << "FRULA";
    else
    {
        while(!stringStack.empty())
        {
            ans.push_back(stringStack.top());
            stringStack.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}