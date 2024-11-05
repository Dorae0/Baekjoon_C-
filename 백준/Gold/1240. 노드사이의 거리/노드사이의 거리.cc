#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF ~0U >> 2

using namespace std;
int n, m, startNode, endNode, weight;

vector<pair<int, int>>edges[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int Dist[MAX];

void Init();
void DistInit();
void Dijkstra(int node);

int main()
{
	Init();
	for (int i = 0; i < m; i++)
	{
		cin >> startNode >> endNode;
		Dijkstra(startNode);
		cout << Dist[endNode] << '\n';
	}
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> startNode >> endNode >> weight;
		edges[startNode].push_back({ weight, endNode });
		edges[endNode].push_back({ weight, startNode });
	}
}

void DistInit()
{
	for (int i = 1; i <= n; i++)
		Dist[i] = INF;
}

void Dijkstra(int node)
{
	DistInit();
	Dist[node] = 0;
	pq.push({ 0, node });
	while (!pq.empty())
	{
		int CurrentDistance = pq.top().first;
		int CurrentNode = pq.top().second;
		pq.pop();
		for (int i = 0; i < edges[CurrentNode].size(); i++)
		{
			int NextDistance = edges[CurrentNode][i].first;
			int NextNode = edges[CurrentNode][i].second;
			if (Dist[NextNode] > CurrentDistance + NextDistance)
			{
				Dist[NextNode] = CurrentDistance + NextDistance;
				pq.push({ Dist[NextNode], NextNode });
			}
		}
	}
}