#include <iostream>
#define MAX 100'001

using namespace std;
int g, p, a, ans, parent[MAX];

void Init();
void Union(int x, int y);
int Find(int x);
void Airport();

int main()
{
	Init();
	Airport();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> g >> p;
	for (int i = 0; i <= g; i++)
		parent[i] = i;
}

void Union(int x, int y)
{
	x = Find(x); y = Find(y);
	if (x > y) swap(x, y);
	parent[y] = x;
}

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Airport()
{
	for (int i = 0; i < p; i++)
	{
		cin >> a;
		a = Find(a);
		if (a == 0) break;
		Union(a, a - 1);
		ans++;
	}
	cout << ans;
}