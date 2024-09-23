#include <iostream>
#define MAX 1001
#define INF ~0U >> 2

using namespace std;
int n, m, startNode, endNode, nodeDistance;
int map[MAX][MAX];
int Dist[MAX];
bool visited[MAX];

void Init();
int FindNewNode();
void Update(int node);
void Dijkstra();

int main()
{
    cin >> n >> m;
    Init();
    for(int i = 0; i < m; i++)
    {
        cin >> startNode >> endNode >> nodeDistance;
        map[startNode][endNode] = min(map[startNode][endNode], nodeDistance);
    }
    cin >> startNode >> endNode;
    Dijkstra();
    cout << Dist[endNode];
}

void Init()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            map[i][j] = INF;
    for(int i = 1; i <= n; i++)
        Dist[i] = INF;
}

int FindNewNode()
{
    int min_dist = INF;
    int min_node = -1;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        if(Dist[i] < min_dist)
        {
            min_dist = Dist[i];
            min_node = i;
        }
    }
    return min_node;
}

void Update(int node)
{
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        if(Dist[i] > Dist[node] + map[node][i])
            Dist[i] = Dist[node] + map[node][i];
    }
}

void Dijkstra()
{
    for(int i = 1; i <= n; i++)
        Dist[i] = map[startNode][i];
    Dist[startNode] = 0;
    visited[startNode] = true; // 초기 설정
    for(int i = 0; i < n - 1; i++)
    {
        int newNode = FindNewNode();
        visited[newNode] = true;
        Update(newNode);
    }
}