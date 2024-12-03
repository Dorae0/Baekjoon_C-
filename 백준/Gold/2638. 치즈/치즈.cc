#include <iostream>
#include <queue>
#define MAX 100

using namespace std;
int n, m, ans;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> cheese;

void init();
bool isValid(int posX, int posY);
void fetchMap();
void meltingCheese();

int main()
{
	init();
	while (!cheese.empty())
	{
		meltingCheese();
		ans++;
	}
	cout << ans;
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				cheese.push({ j, i });
		}
}

bool isValid(int posX, int posY)
{
	if (posY >= 0 && posY < n && posX >= 0 && posX < m)
		return true;
	return false;
}

void fetchMap()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	visited[0][0] = true;
	while (!q.empty())
	{
		int currentPosX = q.front().first;
		int currentPosY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextPosX = currentPosX + dx[i];
			int nextPosY = currentPosY + dy[i];
			if (isValid(nextPosX, nextPosY) && !visited[nextPosY][nextPosX] && map[nextPosY][nextPosX] != 1)
			{
				visited[nextPosY][nextPosX] = true;
				map[nextPosY][nextPosX] = -1;
				q.push({ nextPosX , nextPosY });
			}
		}
	}
}

void meltingCheese()
{
	fetchMap();

	int currentCheeseSize = cheese.size();

	for (int i = 0; i < currentCheeseSize; i++)
	{
		int currentPosX = cheese.front().first;
		int currentPosY = cheese.front().second;
		cheese.pop();
		int airCount = 0;
		for (int k = 0; k < 4; k++)
		{
			if (isValid(currentPosX + dx[k], currentPosY + dy[k]) && map[currentPosY + dy[k]][currentPosX + dx[k]] == -1)
				airCount++;
			if (airCount >= 2)
			{
				map[currentPosY][currentPosX] = 2;
				break;
			}
		}
		if (airCount < 2)
			cheese.push({ currentPosX , currentPosY });
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[j][i] == 2)
				map[j][i] = -1;
}