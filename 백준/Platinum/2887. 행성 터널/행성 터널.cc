#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;
using pli = pair<long long, int>;

class Edge {
public:
	int node[2];
	long long distance;
	Edge(int startNode, int endNode, long long distance)
	{
		this->node[0] = startNode;
		this->node[1] = endNode;
		this->distance = distance;
	}
	bool operator< (Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

long long n, x, y, z;
vector<pli> v[3];
vector<Edge> edges;
bool check[MAX];
int parent[MAX];

void init();
void Union(int x, int y);
int Find(int x);
bool checkCycle(int x, int y);
void kruskal();

int main()
{
	init();
	kruskal();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		v[0].push_back({ x, i });
		v[1].push_back({ y, i });
		v[2].push_back({ z, i });
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());
	for (int i = 0; i < n - 1; i++)
		for(int j = 0; j < 3; j++)
			edges.push_back(Edge(v[j][i].second, v[j][i + 1].second, v[j][i + 1].first - v[j][i].first));
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

bool checkCycle(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}

void kruskal()
{
	long long sum = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (!checkCycle(edges[i].node[0], edges[i].node[1]))
		{
			sum += edges[i].distance;
			Union(edges[i].node[0], edges[i].node[1]);
		}
	}
	cout << sum;
}