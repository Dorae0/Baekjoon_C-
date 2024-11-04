#include <iostream>
#include <vector>
#include <queue>

#define MAX 126
#define INF ~0U >> 2

using namespace std;
int n, Count;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[MAX][MAX];
int Distance[MAX][MAX];

void Init();
void mapInit();
void DistInit();
bool IsValid(int x, int y);
void Dijkstra();

int main()
{
    Init();
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        mapInit();
        DistInit();
        Dijkstra();
        cout << "Problem " << ++Count << ": " << Distance[n][n] << '\n';
    }
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
}

void DistInit()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            Distance[i][j] = INF;
}

void mapInit()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
}

bool IsValid(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= n)
        return true;
    return false;
}

void Dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({map[1][1], {1, 1}});
    Distance[1][1] = map[1][1];
    while(!pq.empty())
    {
        int CurrentPosX = pq.top().second.first;
        int CurrentPosY = pq.top().second.second;
        int CurrentDistance = pq.top().first;
        pq.pop();
        for(int i = 0; i < 4; i++)
        {
            int NextPosX = CurrentPosX + dx[i];
            int NextPosY = CurrentPosY + dy[i];
            if(IsValid(NextPosX, NextPosY))
            {
                int NextDistance = map[NextPosY][NextPosX];
                if(Distance[NextPosY][NextPosX] > CurrentDistance + NextDistance)
                {
                    Distance[NextPosY][NextPosX] = CurrentDistance + NextDistance;
                    pq.push({Distance[NextPosY][NextPosX], {NextPosX, NextPosY}});
                }
            }
        }
    }
}