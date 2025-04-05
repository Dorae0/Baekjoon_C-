#include <iostream>
#include <vector>

#define MAX 20

using namespace std;

enum direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	DIRECTIION_MAX
};

int n, temp, ans;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<int>> map;

void Init();
vector<vector<int>> Move(vector<vector<int>> currentMap, int direction);
void Game(vector<vector<int>> currentMap, int count);

int main()
{
	Init();
	Game(map, 0);
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			tmp.push_back(temp);
		}
		map.push_back(tmp);
	}
}

vector<vector<int>> Move(vector<vector<int>> currentMap, int direction)
{
	bool isMerged[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			isMerged[i][j] = false;
	
	switch (direction)
	{
	case LEFT:
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int currentY = j;
				int currentX = i;
				if (currentMap[currentY][currentX] != 0)
				{
					while (currentX >= 1)
					{
						if (currentMap[currentY][currentX - 1] == 0)
							swap(currentMap[currentY][currentX - 1], currentMap[currentY][currentX]);
						else if (currentMap[currentY][currentX - 1] == currentMap[currentY][currentX] && !isMerged[currentY][currentX - 1])
						{
							currentMap[currentY][currentX - 1] *= 2;
							currentMap[currentY][currentX] = 0;
							isMerged[currentY][currentX - 1] = true;
							break;
						}
						else
							break;
						currentX--;
					}
				}
			}
		}
		break;
	case RIGHT:
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				int currentY = j;
				int currentX = i;
				if (currentMap[currentY][currentX] != 0)
				{
					while (currentX < n - 1)
					{
						if (currentMap[currentY][currentX + 1] == 0)
							swap(currentMap[currentY][currentX + 1], currentMap[currentY][currentX]);
						else if (currentMap[currentY][currentX + 1] == currentMap[currentY][currentX] && !isMerged[currentY][currentX + 1])
						{
							currentMap[currentY][currentX + 1] *= 2;
							currentMap[currentY][currentX] = 0;
							isMerged[currentY][currentX + 1] = true;
							break;
						}
						else
							break;
						currentX++;
					}
				}
			}
		}
		break;
	case UP:
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int currentY = i;
				int currentX = j;
				if (currentMap[currentY][currentX] != 0)
				{
					while (currentY >= 1)
					{
						if (currentMap[currentY - 1][currentX] == 0)
							swap(currentMap[currentY - 1][currentX], currentMap[currentY][currentX]);
						else if (currentMap[currentY - 1][currentX] == currentMap[currentY][currentX] && !isMerged[currentY - 1][currentX])
						{
							currentMap[currentY - 1][currentX] *= 2;
							currentMap[currentY][currentX] = 0;
							isMerged[currentY - 1][currentX] = true;
							break;
						}
						else
							break;
						currentY--;
					}
				}
			}
		}
		break;
	case DOWN:
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				int currentY = i;
				int currentX = j;
				if (currentMap[currentY][currentX] != 0)
				{
					while (currentY < n - 1)
					{
						if (currentMap[currentY + 1][currentX] == 0)
							swap(currentMap[currentY + 1][currentX], currentMap[currentY][currentX]);
						else if (currentMap[currentY + 1][currentX] == currentMap[currentY][currentX] && !isMerged[currentY + 1][currentX])
						{
							currentMap[currentY + 1][currentX] *= 2;
							currentMap[currentY][currentX] = 0;
							isMerged[currentY + 1][currentX] = true;
							break;
						}
						else
							break;
						currentY++;
					}
				}
			}
		}
		break;
	}
	vector<vector<int>> newMap;
	newMap = currentMap;
	return newMap;
}

void Game(vector<vector<int>> currentMap, int count)
{
	for (int i = LEFT; i < DIRECTIION_MAX; i++)
	{
		if (count < 5)
		{
			vector<vector<int>> newMap = Move(currentMap, i);
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					ans = max(ans, newMap[j][k]);
			Game(newMap, count + 1);
		}
	}
}