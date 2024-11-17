#include <iostream>
#define MAX 10

using namespace std;
int n, k;
int ans = ~0U >> 2;
int dist[MAX][MAX];
bool visited[MAX];

void Init();
void DistInit();
void Floyd_Warshall();
void Backtracking(int CurrentNode, int CurrentVal, int Count);

int main()
{
    Init();
    Floyd_Warshall();
    visited[k] = true;
    Backtracking(k, 0, 1);
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    DistInit();
}

void DistInit()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];
}

void Floyd_Warshall()
{
    for(int node = 0; node < n; node++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][j] > dist[i][node] + dist[node][j])
                    dist[i][j] = dist[i][node] + dist[node][j];
}

void Backtracking(int CurrentNode, int CurrentVal, int Count)
{
    if(Count == n)
        ans = min(ans, CurrentVal);
    if(CurrentVal > ans)
        return;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            Backtracking(i, CurrentVal + dist[CurrentNode][i], Count + 1);
            visited[i] = false;
        }
    }
}