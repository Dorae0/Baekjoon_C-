#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define MAX 2000

using namespace std;
int n, m, temp, ans;
string temps;

int visited[MAX][MAX];
vector<string> direction;
vector<vector<int>> cost;
stack<pair<int, int>> path;
stack<pair<int, int>> s;

void Init();
void Maze();
void Check(int PosY, int PosX);
bool IsValid(int PosY, int PosX);
void MazeEscape();
void MazeCycle();

int main()
{
    Init();
    Maze();
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> temps;
        direction.push_back(temps);
    }

    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        cost.push_back(v);
    }
}

void Maze()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
                Check(i, j);
        }
}

void Check(int PosY, int PosX)
{
    while(!s.empty()) s.pop();
    s.push({PosX, PosY});
    while(!s.empty())
    {
        int CurrentPosX = s.top().first;
        int CurrentPosY = s.top().second;
        int NextPosX = CurrentPosX;
        int NextPosY = CurrentPosY;
        visited[CurrentPosY][CurrentPosX] = 2;
        path.push({CurrentPosX, CurrentPosY});
        s.pop();

        switch(direction[CurrentPosY][CurrentPosX])
        {
        case 'R':
            NextPosX++;
            break;
        case 'L' : 
            NextPosX--;
            break;
        case 'U':
            NextPosY--;
            break;
        case 'D' : 
            NextPosY++;
            break;
        }

        if(!IsValid(NextPosY, NextPosX))
            MazeEscape();
        else if(visited[NextPosY][NextPosX] == 2)
        {
            path.push({NextPosX, NextPosY});
            MazeCycle();
        }
        else if(visited[NextPosY][NextPosX] == 1)
            MazeEscape();
        else if(visited[NextPosY][NextPosX] == 0)
            s.push({NextPosX, NextPosY});
    }
}

bool IsValid(int PosY, int PosX)
{
    if(PosY >= 0 && PosY < n && PosX >= 0 && PosX < m)
        return true;
    return false;
}

void MazeEscape()
{
    while(!path.empty())
    {
        int CurrentPosX = path.top().first;
        int CurrentPosY = path.top().second;
        visited[CurrentPosY][CurrentPosX] = 1;
        path.pop();
    }
}

void MazeCycle()
{
    int jumpVal = 501;

    int CyclePosX = path.top().first;
    int CyclePosY = path.top().second;
    int CycleChecked = 0;

    while(!path.empty())
    {
        int CurrentPosX = path.top().first;
        int CurrentPosY = path.top().second;
        path.pop();
        if(CurrentPosX == CyclePosX && CurrentPosY == CyclePosY)
            CycleChecked++;
        if(CycleChecked < 2)
            jumpVal = min(jumpVal, cost[CurrentPosY][CurrentPosX]);
        visited[CurrentPosY][CurrentPosX] = 1;
    }
    ans += jumpVal;
}