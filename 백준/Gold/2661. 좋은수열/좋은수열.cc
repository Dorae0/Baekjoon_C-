#include <iostream>
#include <string>

using namespace std;
int n;
string s;
bool IsChecked;

bool Check(char i);
void Solve(int count);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    Solve(0);
    return 0;
}

bool Check(char c)
{
    s.push_back(c);
    int s_len = s.length();
    int i = 0; int j = 0;
    for(i = 0; i < s_len / 2; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(s[s_len - (j + 1)] != s[s_len - (i + j + 2)])
                break;
        }
        if(j > i)
        {
            s.pop_back();
            return false;
        }
    }
    s.pop_back();
    return true;
}

void Solve(int count)
{
    if(count == n && !IsChecked)
    {
        IsChecked = true;
        cout << s;
        return;
    }
    if(IsChecked)
        return;
    for(int i = 1; i < 4; i++)
    {
        char CurrentNumToChar = i + '0';
        if(Check(CurrentNumToChar))
        {
            s.push_back(CurrentNumToChar); 
            Solve(count + 1);
            s.pop_back();
        }
    }
}