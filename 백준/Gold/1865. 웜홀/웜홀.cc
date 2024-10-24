#include <iostream>
#include <vector>
#define MAX 2701
#define INF ~0U >> 2

using namespace std;
int tc, n, m, w;
int s, e, t;
int Dist[MAX];
vector <pair<int, int>> edge;
int map[MAX][MAX];
void Init();
void DistInit();
void EdgeInit();
void MapInit();
void Bellman_Ford();

int main()
{
    Init();
    for(int i = 0; i < tc; i++)
        Bellman_Ford();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> tc;
}

void DistInit()
{
    for(int i = 0; i < MAX; i++)
        Dist[i] = INF;
}

void EdgeInit()
{
    while(!edge.empty())
        edge.pop_back();
}

void MapInit()
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            map[i][j] = INF;
}

void Bellman_Ford()
{
    cin >> n >> m >> w;
    DistInit();
    EdgeInit();
    MapInit();
    Dist[1] = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        if(map[s][e] == INF)
            edge.push_back({s, e});
        map[s][e] = min(map[s][e], t);
        if(map[e][s] == INF)
            edge.push_back({e, s});
        map[e][s] = min(map[e][s], t);
    }
    for(int i = 0; i < w; i++)
    {
        cin >> s >> e >> t;
        if(map[s][e] == INF)
            edge.push_back({s, e});
        map[s][e] = min(map[s][e], -t);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < edge.size(); j++)
        {
            int StartNode = edge[j].first;
            int EndNode = edge[j].second;
            int Weight = map[StartNode][EndNode];

            // if(Dist[StartNode] == INF) continue;
            if(Dist[EndNode] > Dist[StartNode] + Weight) Dist[EndNode] = Dist[StartNode] + Weight;
        }
    }
    for(int j = 0; j < edge.size(); j++)
    {
        int StartNode = edge[j].first;
        int EndNode = edge[j].second;
        int Weight = map[StartNode][EndNode];

        // if(Dist[StartNode] == INF) continue;
        if(Dist[EndNode] > Dist[StartNode] + Weight)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}