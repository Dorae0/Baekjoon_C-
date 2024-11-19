#include <iostream>
#include <queue>
#define MAX 8

using namespace std;
int m, n, ans;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void Init();
void Backtracking(int Count);
bool IsValid(int Y, int X);
int BFS();

int main()
{
    Init();
    Backtracking(0);
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
}

void Backtracking(int Count)
{
    if(Count == 3)
    {
        ans = max(ans, BFS());
        return;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j] && !map[i][j])
            {
                visited[i][j] = true;
                map[i][j] = 1;
                Backtracking(Count + 1);
                visited[i][j] = false;
                map[i][j] = 0;
            }
}

bool IsValid(int Y, int X)
{
    if(Y >= 0 && Y < n && X >= 0 && X < m)
        return true;
    return false;
}

int BFS()
{
    int Cmap[MAX][MAX];
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            Cmap[i][j] = map[i][j];
            if(Cmap[i][j] == 2)
                q.push({j, i});
        }
    while(!q.empty())
    {
        int CurrentPosX = q.front().first;
        int CurrentPosY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int NextPosX = CurrentPosX + dx[i];
            int NextPosY = CurrentPosY + dy[i];
            if(IsValid(NextPosY, NextPosX))
            {
                if(Cmap[NextPosY][NextPosX] == 0)
                {
                    Cmap[NextPosY][NextPosX] = 2;
                    q.push({NextPosX, NextPosY});
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(Cmap[i][j] == 0)
                ans++;
    return ans;
}