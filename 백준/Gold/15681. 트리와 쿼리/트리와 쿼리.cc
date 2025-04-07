#include <iostream>
#include <vector>

#define MAX 100'001

using namespace std;

int n, r, q, u, v, temp;
int parent[MAX], subTreeSize[MAX];
vector<int> edges[MAX], child[MAX];

void Init();
void MakeTree(int node, int parentNode);
void CountSubtreeNodes(int node);

int main()
{
	Init();
	MakeTree(r, -1);
	CountSubtreeNodes(r);
	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		cout << subTreeSize[temp] << '\n';
	}
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
}

void MakeTree(int node, int parentNode)
{
	parent[node] = parentNode;
	for (int i = 0; i < edges[node].size(); i++)
	{
		if (edges[node][i] != parentNode)
		{
			child[node].push_back(edges[node][i]);
			MakeTree(edges[node][i], node);
		}
	}
}

void CountSubtreeNodes(int node)
{
	subTreeSize[node] = 1;
	for (int i = 0; i < child[node].size(); i++)
	{
		CountSubtreeNodes(child[node][i]);
		subTreeSize[node] += subTreeSize[child[node][i]];
	}
}