#include <iostream>
#include <queue>
#include <string>
#define MAX 51
#define INF ~0U >> 2

using namespace std;
int n;
int map[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Init();
bool IsValid(int PosY, int PosX);
void Dijkstra();

struct mapVal{
    int Dist;
    int PosX;
    int PosY;
       bool operator>(const mapVal& other) const {
        return Dist > other.Dist;
    }
};

int main()
{
    Init();
    Dijkstra();
    cout << dist[n - 1][n - 1];
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < n; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }


    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INF;
}

bool IsValid(int PosY, int PosX)
{
    if(PosY >= 0 && PosY < n && PosX >= 0 && PosX < n)
        return true;
    return false;
}

void Dijkstra()
{
    priority_queue<mapVal, vector<mapVal>, greater<mapVal>> pq;
    mapVal m = {0, 0, 0};
    dist[0][0] = 0;
    pq.push(m);
    while(!pq.empty())
    {
        int CurrentPosX = pq.top().PosX;
        int CurrentPosY = pq.top().PosY;
        int CurrentDist = pq.top().Dist;
        pq.pop();
        for(int i = 0; i < 4; i++)
        {
            int NextPosX = CurrentPosX + dx[i];
            int NextPosY = CurrentPosY + dy[i];
            if(IsValid(NextPosY, NextPosX))
            {
                int NextDist = 1 - map[NextPosY][NextPosX];
                if(dist[NextPosY][NextPosX] > CurrentDist + NextDist)
                {
                    dist[NextPosY][NextPosX] = CurrentDist + NextDist;
                    mapVal m = {dist[NextPosY][NextPosX], NextPosX, NextPosY};
                    pq.push(m);
                }
            }
        }
    }
}