#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
using piv = pair<int, vector<int>>;
struct changeOrder {
	int l, r, c;
};
int n, a, m, l, r, c;
vector<int> A;
vector<changeOrder> M;
priority_queue <piv, vector<piv>, greater<piv>> pq;
map<vector<int>, int> dist;

void Init();
void Dijkstra();

int main()
{
	Init();
	Dijkstra();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		A.push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r >> c;
		M.push_back(changeOrder{ l, r, c });
	}
	pq.push({ 0, A });
	sort(A.begin(), A.end());
}

void Dijkstra()
{
	while (!pq.empty())
	{
		int currentDist = pq.top().first;
		vector<int> currentNode = pq.top().second;
		pq.pop();
		if (dist[currentNode] < currentDist)
			continue;
		for (int i = 0; i < m; i++)
		{
			swap(currentNode[M[i].l - 1], currentNode[M[i].r - 1]);
			if (dist.find(currentNode) == dist.end() || dist[currentNode] > currentDist + M[i].c)
			{
				dist[currentNode] = currentDist + M[i].c;
				pq.push({ currentDist + M[i].c, currentNode });
			}
			swap(currentNode[M[i].l - 1], currentNode[M[i].r - 1]);
		}
	}
	if (dist.find(A) == dist.end())
		cout << -1;
	else cout << dist[A];
}