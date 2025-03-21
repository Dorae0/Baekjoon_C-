#include <iostream>

using namespace std;
bool ans;
int n;
int map[3][3];
bool visited[3][3];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void Init();
bool IsValid(int x, int y);
void DFS(int x, int y);

int main()
{
	Init();
	DFS(0, 0);
	if (ans)
		cout << "HaruHaru";
	else
		cout << "Hing";
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

bool IsValid(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

void DFS(int x, int y)
{
	if (ans || visited[y][x])
		return;
	visited[y][x] = true;
	if (x == n - 1 && y == n - 1)
	{
		ans = true;
		return;
	}
	int currentMap = map[y][x];
	for (int i = 0; i < 2; i++)
	{
		int nextX = x + dx[i] * currentMap;
		int nextY = y + dy[i] * currentMap;
		if (IsValid(nextX, nextY))
			DFS(nextX, nextY);
	}
}