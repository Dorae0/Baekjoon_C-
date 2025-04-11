#include <iostream>
#include <queue>

#define MAX 32001

using namespace std;
int n, m, s, e, inDegree[MAX];
vector<int> edges[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

void Init();
void TopologySort();

int main()
{
	Init();
	TopologySort();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		edges[s].push_back(e);
		inDegree[e]++;
	}
}

void TopologySort()
{
	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			pq.push(i);

	while (!pq.empty())
	{
		int currentNum = pq.top();
		cout << currentNum << ' ';
		pq.pop();
		for (int i = 0; i < edges[currentNum].size(); i++)
		{
			inDegree[edges[currentNum][i]]--;
			if (!inDegree[edges[currentNum][i]])
				pq.push(edges[currentNum][i]);
		}
	}
}