#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int n, x, y;
vector<int> vertex[MAX];
int ans[MAX];
bool visited[MAX];

void Init();
void DFS(int n);
void Print();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    Init();
    DFS(1);
    Print();
}

void Init()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
}

void DFS(int n)
{
    visited[n] = true;
    for(int i = 0; i < vertex[n].size(); i++)
    {
        int CurrentNode = vertex[n][i];
        if(!visited[CurrentNode])
        {
            ans[CurrentNode] = n;
            DFS(CurrentNode);
        }
    }
}

void Print()
{
    for(int i = 2; i <= n; i++)
        cout << ans[i] << '\n';
}