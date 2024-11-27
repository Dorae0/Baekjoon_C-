#include <iostream>
#include <vector>
#include <queue>
#define MAX 50001
#define INF ~0U >> 2

using namespace std;
int n, m, s, e, w;

vector<pair<int, int>> edges[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[MAX];

void init();
void distInit();
void dijkstra();

int main()
{
    init();
    dijkstra();
    cout << dist[n];
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> w;
        edges[s].push_back({w, e});
        edges[e].push_back({w, s});
    }
    distInit();
}

void distInit()
{
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
}

void dijkstra()
{
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        for(int i = 0; i < edges[currentNode].size(); i++)
        {
            int nextDist = edges[currentNode][i].first;
            int nextNode = edges[currentNode][i].second;
            if(dist[nextNode] > currentDist + nextDist)
            {
                dist[nextNode] = currentDist + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}