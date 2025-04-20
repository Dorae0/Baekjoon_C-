#include <iostream>
#define MAX 500'000

using namespace std;
int n, m, s, e, parent[MAX];

void Init();
void Union(int x, int y);
int Find(int x);
void CycleGame();

int main()
{
	Init();
	CycleGame();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

void Union(int x, int y)
{
	x = Find(x); y = Find(y);
	if (x > y) swap(x, y);
	parent[x] = y;
}

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void CycleGame()
{
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> e;
		if (Find(s) == Find(e))
		{
			cout << i;
			return;
		}
		Union(s, e);
	}
	cout << 0;
}