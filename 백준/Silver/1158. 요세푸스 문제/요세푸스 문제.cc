#include <iostream>
#include <queue>
#define MAX 5000
using namespace std;

int n, k;
int Order[MAX];
queue<int> numbers;

void QueueInit();
void Rotate();
void Josephus();
void Print();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    QueueInit();
    Josephus();
    Print();
}

void QueueInit()
{
    for(int i = 1; i <= n; i++)
        numbers.push(i);
}

void Rotate()
{
    numbers.push(numbers.front());
    numbers.pop();
}

void Josephus()
{
    int nnum = 0;
    while(!numbers.empty())
    {
        int knum = k - 1;
        while(knum--)
        {
            Rotate();
        }
        Order[nnum++] = numbers.front();
        numbers.pop();
    }
}

void Print()
{
    cout << '<';
    for(int i = 0; i < n - 1; i++)
        cout << Order[i] << ", ";
    cout << Order[n-1] << '>';
}