#include <iostream>
#include <queue>
#define MAX 500

using namespace std;

int n, m, pictureCount, pictureMax;
int map[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAX][MAX];
queue<pair<int, int>> q;

bool IsValid(int x, int y);
void BFS();

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && map[i][j] == 1)
			{
				visited[i][j] = true;
				q.push({ j, i });
				BFS();
			}
	
	cout << pictureCount << '\n' << pictureMax;
}

bool IsValid(int x, int y)
{
	if (x >= 0 && x < m && y >= 0 && y < n)
		return true;
	else
		return false;
}

void BFS()
{
	int pictureSize = 0;
	while (!q.empty())
	{
		pictureSize++;
		int CurrentX = q.front().first;
		int CurrentY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int NextX = CurrentX + dx[i];
			int NextY = CurrentY + dy[i];
			if (IsValid(NextX, NextY) && !visited[NextY][NextX] && map[NextY][NextX] == 1)
			{
				visited[NextY][NextX] = true;
				q.push({ NextX, NextY });
			}
		}
	}
	pictureCount++;
	pictureMax = max(pictureMax, pictureSize);
}