#include <iostream>
#include <string>
#define MAX 64
#define MIXED 2

using namespace std;
int n;
string map[MAX];
int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };

void Init();
int CheckMap(int startX, int startY, int size);
void DNC(int startX, int startY, int size);

int main()
{
	Init();
	DNC(0, 0, n);
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
}

int CheckMap(int startX, int startY, int size)
{
	int endX = startX + size - 1;
	int endY = startY + size - 1;
	int firstTile = map[startY][startX];
	for (int i = startY; i <= endY; i++)
		for (int j = startX; j <= endX; j++)
			if (map[i][j] != firstTile)
				return MIXED;
	return firstTile - '0';
}

void DNC(int startX, int startY, int size)
{
	int CurrentCheckMap = CheckMap(startX, startY, size);
	if (CurrentCheckMap != MIXED)
		cout << CurrentCheckMap;
	else
	{
		cout << '(';
		for (int i = 0; i < 4; i++)
			DNC(startX + dx[i] * size / 2, startY + dy[i] * size / 2, size / 2);
		cout << ')';
	}
}