#include <iostream>
#define MAX 1025
#define Y 0
#define X 1

using namespace std;

int n, m, k;
int point[2][2];
int mp[MAX][MAX];

void Init();
void Solve();

int main()
{
	Init();
	Solve();
}

void Init()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			mp[i][j] += (mp[i][j - 1] + mp[i - 1][j] - mp[i - 1][j - 1]);
		}
}

void Solve()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> point[j / 2][j % 2];
		cout << mp[point[1][Y]][point[1][X]] - mp[point[0][Y] - 1][point[1][X]] - mp[point[1][Y]][point[0][X] - 1] + mp[point[0][Y] - 1][point[0][X] - 1] << '\n';
	}
}