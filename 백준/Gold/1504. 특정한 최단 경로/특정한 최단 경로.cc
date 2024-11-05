#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
#define INF ~0U >> 2

using namespace std;

int n, e, a, b, c;
int node1, node2;
int dist[MAX];
vector<pair<int, int>> edges[MAX];
int dists[3][2];

void Init();
void DistInit();
void Dijkstra(int node);

int main()
{
    Init();
    Dijkstra(1);
    dists[0][0] = dist[node1];
    dists[0][1] = dist[node2];
    Dijkstra(node1);
    dists[1][0] = dist[node2];
    dists[1][1] = dist[n];
    Dijkstra(node2);
    dists[2][0] = dist[n];
    dists[2][1] = dist[node1];
    int ans = min(dists[0][0] + dists[1][0] + dists[2][0], dists[0][1] + dists[1][1] + dists[2][1]);
    if(ans >= INF) cout << -1;
    else cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }
    cin >> node1 >> node2;
}

void DistInit()
{
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
}

void Dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    DistInit();
    dist[node] = 0;
    while(!pq.empty())
    {
        int CurrentDist = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();
        for(int i = 0; i < edges[CurrentNode].size(); i++)
        {
            int NextDist = edges[CurrentNode][i].first;
            int NextNode = edges[CurrentNode][i].second;
            if(dist[NextNode] > CurrentDist + NextDist)
            {
                dist[NextNode] = CurrentDist + NextDist;
                pq.push({dist[NextNode], NextNode});
            }
        }
    }
}