#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF ~0U >> 2

using namespace std;

int n, m, startNode, endNode, nodeDistance;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> vertex[MAX];
int Dist[MAX];
int PathArr[MAX];
vector<int> v;

void SolvePaths();
void VectorInit();
void Dijkstra();
void DistInit();
void Backtracking(int count);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    DistInit();
    for(int i = 0; i < m; i++)
    {
        cin >> startNode >> endNode >> nodeDistance;
        vertex[startNode].push_back({nodeDistance, endNode});
    }
    cin >> startNode >> endNode;
    Dijkstra();
    cout << Dist[endNode] << '\n';
    SolvePaths();
    int Vsize = v.size();
    cout << Vsize << '\n';
    for(int i = 0; i < Vsize; i++)
        cout << v[Vsize - 1 - i] << ' ';
}

void SolvePaths()
{
    v.push_back(endNode);
    int temp = PathArr[endNode];
    while(temp != startNode)
    {
        v.push_back(temp);
        temp = PathArr[temp];
    }
    v.push_back(startNode);
}

void DistInit()
{
    for(int i = 0 ;i < MAX; i++)
        Dist[i] = INF;
}

void Dijkstra()
{
    pq.push({0, startNode});
    Dist[startNode] = 0;

    while(!pq.empty())
    {
        int CurrentDistance = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();
        if(CurrentDistance > Dist[CurrentNode]) continue;
        for(int i = 0; i < vertex[CurrentNode].size(); i++)
        {
            int NextDistance = vertex[CurrentNode][i].first;
            int NextNode = vertex[CurrentNode][i].second;
            if(Dist[NextNode] > CurrentDistance + NextDistance)
            {
                PathArr[NextNode] = CurrentNode;
                Dist[NextNode] = CurrentDistance + NextDistance;
                pq.push({Dist[NextNode], NextNode});
            }
        }
    }
}