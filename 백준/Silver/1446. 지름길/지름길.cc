#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
#define INF ~0U >> 2

using namespace std;

int n, d, s, e, w;
int dist[MAX];
vector<pair<int, int>> edges[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Init();
void DistInit();
void Dijkstra();

int main()
{
	Init();
	DistInit();
	Dijkstra();
	cout << dist[d];
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> s >> e >> w;
		edges[s].push_back({w, e});
	}
	for(int i = 0; i < d; i++)
		edges[i].push_back({1, i + 1});
}

void DistInit()
{
	for(int i = 0; i <= d; i++)
		dist[i] = INF;
}

void Dijkstra()
{
	pq.push({0, 0});
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