#include <iostream>
#include <vector>
#define MAX 501
#define INF ~0U >> 2

using namespace std;

int n, m, s, e, w;
vector<pair<int, int>> edges[MAX];
long long dist[MAX];

void init();
void distInit();
void bellman_ford();

int main()
{
    init();
    distInit();
    bellman_ford();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> w;
        edges[s].push_back({e, w});
    }
}

void distInit()
{
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
}

void bellman_ford()
{
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k < edges[j].size(); k++)
            {
                int startNode = j;
                int endNode = edges[j][k].first;
                int timeCost = edges[j][k].second;

                if(dist[startNode] == INF) continue;
                if(dist[endNode] > dist[startNode] + timeCost)
                    dist[endNode] = dist[startNode] + timeCost;
            }
        }
    }
    for(int j = 1; j <= n; j++)
    {
        for(int k = 0; k < edges[j].size(); k++)
        {
            int startNode = j;
            int endNode = edges[j][k].first;
            int timeCost = edges[j][k].second;

            if(dist[startNode] == INF) continue;
            if(dist[endNode] > dist[startNode] + timeCost)
            {
                cout << -1;
                return;
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << -1 << '\n';
    }
    return;
}