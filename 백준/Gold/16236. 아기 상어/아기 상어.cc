#include <iostream>
#include <queue>
#define MAX 20

using namespace std;
int n, sharkX, sharkY;
int sharkSize = 2;
int sharkEXP = 0;
int ansTime = 0;
int ansDist = -1, ansPosX, ansPosY;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init();
void visitedInit();
bool isValid(int posX, int posY);
void babyShark();

int main()
{
	init();
	while (1)
	{
		babyShark();
		if (ansDist == -1)
			break;
		sharkX = ansPosX;
		sharkY = ansPosY;
		ansTime += ansDist;
		map[sharkY][sharkX] = 0;
		sharkEXP++;
		if (sharkEXP >= sharkSize)
		{
			sharkEXP -= sharkSize;
			sharkSize++;
		}
	}
	cout << ansTime;
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				sharkX = j;
				sharkY = i;
				map[i][j] = 0;
			}
		}
}

void visitedInit()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
}

bool isValid(int posX, int posY)
{
	if (posX >= 0 && posX < n && posY >= 0 && posY < n)
		return true;
	return false;
}

void babyShark()
{
	visitedInit();
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sharkX, sharkY}, 0 });
	visited[sharkY][sharkX] = true;
	ansDist = -1;
	ansPosX = 0;
	ansPosY = 0;
	while (!q.empty())
	{
		int currentPosX = q.front().first.first;
		int currentPosY = q.front().first.second;
		int currentDist = q.front().second;
		if (ansDist > 0 && ansDist < currentDist)
			break;
		if (map[currentPosY][currentPosX] > 0 && map[currentPosY][currentPosX] < sharkSize)
		{
			if (ansDist == -1)
			{
				ansDist = currentDist;
				ansPosX = currentPosX;
				ansPosY = currentPosY;
			}
			else if (ansDist == currentDist)
			{
				if (ansPosY > currentPosY)
				{
					ansPosX = currentPosX;
					ansPosY = currentPosY;
				}
				else if (ansPosY == currentPosY && ansPosX > currentPosX)
				{
					ansPosX = currentPosX;
					ansPosY = currentPosY;
				}
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextPosX = currentPosX + dx[i];
			int nextPosY = currentPosY + dy[i];
			if (isValid(nextPosX, nextPosY) && map[currentPosY][currentPosX] <= sharkSize && !visited[nextPosY][nextPosX])
			{
				visited[nextPosY][nextPosX] = true;
				q.push({ { nextPosX, nextPosY }, currentDist + 1 });
			}
		}
	}
}