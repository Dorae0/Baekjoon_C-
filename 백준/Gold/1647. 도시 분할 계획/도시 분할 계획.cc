#include <iostream>
#include <queue>
#define MAX 100'001

using namespace std;
using piii = pair<int, pair<int, int>>;
priority_queue<piii, vector<piii>, greater<piii>> pq;

int n, m, x, y, w, ans, maxWeight, parent[MAX], ran[MAX];

void Init();
void Union(int x, int y);
int Find(int x);
void Kruskal();

int main()
{
	Init();
	Kruskal();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		pq.push({ w, {x, y} });
	}
	for (int i = 1; i < MAX; i++)
	{
		parent[i] = i;
		ran[i] = 1;
	}
 }

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (ran[x] > ran[y]) swap(x, y);
	parent[x] = y;
	if (ran[x] == ran[y]) ran[y]++;
}

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Kruskal()
{
	while (!pq.empty())
	{
		piii currentEdge = pq.top();
		pq.pop();
		if (Find(currentEdge.second.first) != Find(currentEdge.second.second))
		{
			Union(currentEdge.second.first, currentEdge.second.second);
			ans += currentEdge.first;
			maxWeight = max(maxWeight, currentEdge.first);
		}
	}
	cout << ans - maxWeight;
}