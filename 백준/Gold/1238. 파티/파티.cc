#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF ~0U >> 2

using namespace std;
int n, m, x, startNode, endNode, nodeDistance, maxVal;
vector<pair<int, int>> vertex[MAX];
int Dist[MAX];

void InitDist();
void Dijkstra();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
    {
        cin >> startNode >> endNode >> nodeDistance;
        vertex[startNode].push_back({nodeDistance, endNode});
    }

    for(int i = 1; i <= n; i++)
    {
        int CurrentVal = 0;
        InitDist();
        startNode = i; endNode = x;
        Dijkstra();
        CurrentVal += Dist[endNode];
        InitDist();
        startNode = x; endNode = i;
        Dijkstra();
        CurrentVal += Dist[endNode];
        maxVal = max(maxVal, CurrentVal);
    }
    cout << maxVal;
}

void InitDist()
{
    for(int i = 1; i <= n; i++)
        Dist[i] = INF;
}


void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});
    Dist[startNode] = 0;

    while(!pq.empty())
    {
        int CurrentCost = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        for(int i = 0; i < vertex[CurrentNode].size(); i++)
        {
            int NextCost = vertex[CurrentNode][i].first;
            int NextNode = vertex[CurrentNode][i].second;
            if(Dist[NextNode] > CurrentCost + NextCost)
            {
                Dist[NextNode] = CurrentCost + NextCost;
                pq.push({Dist[NextNode], NextNode});
            }
        }
    }
}