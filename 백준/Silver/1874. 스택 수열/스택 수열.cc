#include <iostream>
#include <stack>

#define MAX 200000

using namespace std;
stack<int> s;
int n, x, checknum, arrindex;
bool isValid = true;
char v[MAX];

void push();
bool pop();
void print();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(checknum < x)
        {
            push();
            pop();
        }
        else
        {
            if(!pop())
            {
                isValid = false;
                break;
            }
        }
    }
    print();

    return 0;
}

void push()
{
    for(int i = checknum + 1; i <= x; i++)
    {
        v[arrindex++] = '+';
        s.push(i);
    }
    checknum = x;
}

bool pop()
{
    if(s.top() == x)
    {
        s.pop();
        v[arrindex++] = '-';
        return true;
    }
    else
        return false;
}

void print()
{
    if(isValid)
    {
        for(int i = 0; i < arrindex; i++)
            cout << v[i] << '\n';
    }
    else
        cout << "NO" << '\n';
}