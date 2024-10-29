#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;
int n, start, node, weight, dist, diameterNode;
int edge_start;
bool visited[MAX];
vector<pair<int, int>> edge[MAX];
void Init();
void SecondInit();
void Diameter(int CurrentNode, int Distance);

int main()
{
    Init();
    Diameter(edge_start, 0);
    SecondInit();
    Diameter(diameterNode, 0);
    cout << dist;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> start;
        while(1)
        {
            cin >> node;
            if(node == -1) break;
            cin >> weight;
            if(edge_start == 0)
                edge_start = node;
            edge[start].push_back({node, weight});
            edge[node].push_back({start, weight});
        }
    }
}

void SecondInit()
{
    for(int i = 0; i < MAX; i++)
        visited[i] = false;
    dist = 0;
}

void Diameter(int CurrentNode, int Distance)
{
    if(visited[CurrentNode]) return;
    if(dist < Distance)
    {
        dist = Distance;
        diameterNode = CurrentNode;
    }
    visited[CurrentNode] = true;
    for(int i = 0; i < edge[CurrentNode].size(); i++)
    {
        int NextNode = edge[CurrentNode][i].first;
        int NextDistance = edge[CurrentNode][i].second;
        Diameter(NextNode, Distance + NextDistance);
    }
}