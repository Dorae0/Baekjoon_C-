#include <iostream>
#include <queue>
#include <string>
#define MAX 1001

using namespace std;
int n, m;
queue<pair<pair<int, int>, int>> q;
int map[MAX][MAX];
int visited[MAX][MAX][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Init();
bool IsValid(int X, int Y);
int BFS();

int main()
{
    Init();
    cout << BFS(); 
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
            map[i][j] = s[j] - '0';
    }   
}

bool IsValid(int X, int Y)
{
    if(X >= 0 && X < m && Y >= 0 && Y < n)
        return true;
    return false;
}

int BFS()
{
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;
    while(!q.empty())
    {
        int CurrentX = q.front().first.first;
        int CurrentY = q.front().first.second;
        int CurrentWall = q.front().second;
        
        q.pop();
        
        if(CurrentX == m - 1 && CurrentY == n - 1) return visited[CurrentY][CurrentX][CurrentWall];

        for(int i = 0; i < 4; i++)
        {
            int NextX = CurrentX + dx[i];
            int NextY = CurrentY + dy[i];
            if(IsValid(NextX, NextY))
            {
                if(map[NextY][NextX] == 0 && !visited[NextY][NextX][CurrentWall])
                {
                    visited[NextY][NextX][CurrentWall] = visited[CurrentY][CurrentX][CurrentWall] + 1;
                    q.push({{NextX, NextY}, CurrentWall});
                }
                else if(map[NextY][NextX] == 1 && !CurrentWall)
                {
                    visited[NextY][NextX][CurrentWall + 1] = visited[CurrentY][CurrentX][CurrentWall] + 1;
                    q.push({{NextX, NextY}, CurrentWall + 1});
                }
            }
        }
    }
    return -1;
}