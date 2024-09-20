#include <iostream>
#include <stack>
#define MAX 1000000

using namespace std;

int n;
int numArr[MAX];
int NGEArr[MAX];
stack<int> s;

void NGE();
void Print();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> numArr[i];
    NGE();
    Print();
}

void NGE()
{
    for(int i = n - 1; i >= 0;)
    {
        if(s.empty())
        {
            NGEArr[i] = -1;
            s.push(numArr[i]);
            i--;
        }
        else
        {
            if(numArr[i] >= s.top())
                s.pop();
            else
            {
                NGEArr[i] = s.top();
                s.push(numArr[i]);
                i--;
            }
        }
    }
}

void Print()
{
    for(int i = 0; i < n; i++)
        cout << NGEArr[i] << ' ';
}