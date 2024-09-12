#include <iostream>
#include <queue>

#define MAX 100
using namespace std;

queue<int> q;
int n;
bool map[MAX][MAX];
int visited[MAX];

void visitedInit();
void dfs(int x);
void Print();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];

    visitedInit();

    for(int i = 0; i < n; i++)
    {
        visitedInit();
        dfs(i);
    }

    Print();
}

void visitedInit()
{
    for(int i = 0; i < n; i++)
        visited[i] = false;
}

void dfs(int x)
{
    q.push(x);
    while(!q.empty())
    {
        int currentNum = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(map[i][currentNum] == 1 && !visited[i])
            {
                visited[i] = true;
                map[i][x] = 1;
                q.push(i);

            }
        }
    }
}

void Print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
}