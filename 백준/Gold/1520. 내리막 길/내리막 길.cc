#include <iostream>

#define MAX 500

using namespace std;

int m, n;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Init();
bool IsValid(int x, int y);
int DFS(int x, int y);

int main()
{
	Init();
	cout << DFS(0, 0);
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
}

bool IsValid(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int DFS(int x, int y)
{
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (IsValid(newX, newY) && map[y][x] > map[newY][newX])
			dp[y][x] += DFS(newX, newY);
	}

	return dp[y][x];
}