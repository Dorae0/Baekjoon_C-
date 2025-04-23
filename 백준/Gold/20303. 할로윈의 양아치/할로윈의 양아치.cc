#include <iostream>
#include <vector>
#include <algorithm>
#define KIDS_MAX 30'001
#define WEIGHT_MAX 3'001

using namespace std;
int n, m, k, s, e, ans, kids[KIDS_MAX][2], parent[KIDS_MAX], dp[KIDS_MAX][WEIGHT_MAX];
bool visited[KIDS_MAX];
vector<pair<int, int>> kids_group;

void Init();
void Union(int x, int y);
int Find(int x);
void MakeGroup();
void Knapsack();

int main()
{
	Init();
	MakeGroup();
	Knapsack();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> kids[i][0];
		kids[i][1] = 1;
		parent[i] = i;
	}
}

void Union(int x, int y)
{
	x = Find(x); y = Find(y);
	if (x == y) return;
	if (x < y) swap(x, y);
	parent[x] = y;
	kids[y][0] += kids[x][0];
	kids[y][1] += kids[x][1];
}

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void MakeGroup()
{
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		Union(s, e);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[Find(i)])
		{
			visited[Find(i)] = true;
			kids_group.push_back({ kids[Find(i)][0], kids[Find(i)][1] });
		}
	}
}

void Knapsack()
{
	for (int i = 1; i <= kids_group.size(); i++)
	{
		int currentVal = kids_group[i - 1].first;
		int currentWeight = kids_group[i - 1].second;
		for (int j = 1; j <= k - 1; j++)
		{
			if (j - currentWeight >= 0)
				dp[i][j] = max(dp[i - 1][j - currentWeight] + currentVal, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
		ans = max(ans, dp[i][k - 1]);
	}

	cout << ans;
}