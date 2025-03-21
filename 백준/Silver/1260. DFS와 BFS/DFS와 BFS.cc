#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX 1001

using namespace std;

int n, m, v, s, e;
bool visited[MAX];
vector<int> edges[MAX];
stack<int> stck;
queue<int> q;

void Init();
void VisitedInit();
void DFS();
void BFS();


int main()
{
	Init();
	DFS();
	BFS();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}
	for (int i = 0; i < MAX; i++)
		sort(edges[i].begin(), edges[i].end());
}

void VisitedInit()
{
	for (int i = 0; i < MAX; i++)
		visited[i] = false;
}

void DFS()
{
	VisitedInit();
	stck.push(v);

	while (!stck.empty())
	{
		int currentNode = stck.top();
		stck.pop();

		if (visited[currentNode]) continue;
		visited[currentNode] = true;
		cout << currentNode << ' ';

		for (int i = edges[currentNode].size() - 1; i >= 0; i--)
		{
			int nextNode = edges[currentNode][i];
			if (!visited[nextNode])
				stck.push(nextNode);
		}
	}
	cout << '\n';
}

void BFS()
{
	VisitedInit();
	q.push(v);
	visited[v] = true;
	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();
		cout << currentNode << ' ';
		for (int i = 0; i < edges[currentNode].size(); i++)
		{
			int nextNode = edges[currentNode][i];
			if (!visited[nextNode])
			{
				visited[nextNode] = true;
				q.push(nextNode);
			}
		}
	}
	cout << '\n';
}