#include <iostream>
#include <vector>
#define MAX 101
#define INF ~0U >> 2

using namespace std;

int n, m, r, a, b, l;
int dist[MAX][MAX];
int items[MAX];
vector<pair<int, int>> edges[MAX];

void Init();
void Floyd_Warshall();
void DistInit();
void SeogangGround();

int main()
{
    Init();
    Floyd_Warshall();
    SeogangGround();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> r;
    DistInit();
    for(int i = 1; i <= n; i++)
        cin >> items[i];
    for(int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        edges[a].push_back({b, l});
        edges[b].push_back({a, l});
        dist[a][b] = l;
        dist[b][a] = l;
    }
}

void DistInit()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j)
                dist[i][j] = INF;
}

void Floyd_Warshall()
{
    for(int node = 1; node <= n; node++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][j] > dist[i][node] + dist[node][j])
                    dist[i][j] = dist[i][node] + dist[node][j];
}

void SeogangGround()
{
    int maxVal = 0;
    for(int i = 1; i <= n; i++)
    {
        int CurrentVal = 0;
        for(int j = 1; j <= n; j++)
            if(dist[i][j] <= m)
                CurrentVal += items[j];
        maxVal = max(maxVal, CurrentVal);
    }
    cout << maxVal;
}