#include <iostream>
#include <stack>
#define INF ~0U >> 2

using namespace std;
long long a, b;
long long ans = INF;
stack<long long> s;

void Init();
void BFS(long long Count);
long long Calculate(long long num, int type);

int main()
{
    Init();
    BFS(1);
    if(ans != INF)
        cout << ans;
    else
        cout << -1;
}


void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    s.push(a);
}

void BFS(long long Count)
{
    while(!s.empty())
    {
        long long CurrentNum = s.top();
        s.pop();
        if(CurrentNum == b)
            ans = min(ans, Count);
        for(int i = 0; i < 2; i++)
        {
            long long NextNum = Calculate(CurrentNum, i);
            if(NextNum <= b)
            {
                s.push(NextNum);
                BFS(Count + 1);
            }
        }
    }
} 

long long Calculate(long long num, int type)
{
    if(!type)
        return num * 2;
    else
        return num * 10 + 1;
}