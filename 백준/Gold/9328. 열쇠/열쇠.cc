#include <iostream>
#include <string>
#define MAX 102

using namespace std;

int t, h, w, ans;
string s;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char map[MAX][MAX];
bool visited[MAX][MAX];

void Init();
void TestCaseInput();
void VisitedInit();
void OpenDoor(char c);
void Key();
bool IsValid(int x, int y);
void DFS(int x, int y);

int main()
{
	Init();
	for(int i = 0; i < t; i++)
		Key();
}


void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
}

void TestCaseInput()
{
	ans = 0;
	VisitedInit();

	cin >> h >> w;

	for (int i = 0; i < h + 2; i++)
		for (int j = 0; j < w + 2; j++)
			map[i][j] = '.';

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> map[i][j];
	cin >> s;
	if(s != "0")
		for (int i = 0; i < s.length(); i++)
			OpenDoor(s[i]);
}

void VisitedInit()
{
	for (int i = 0; i < h + 2; i++)
		for (int j = 0; j < w + 2; j++)
			visited[i][j] = false;
}

void OpenDoor(char c)
{
	int count = 0;
	for (int i = 0; i < h + 1; i++)
		for (int j = 0; j < w + 1; j++)
			if (map[i][j] == c - 'a' + 'A')
			{
				count++;
				map[i][j] = '.';
			}
	if (count)
		VisitedInit();
}

void Key()
{
	TestCaseInput();
	DFS(0, 0);
	cout << ans << '\n';
}

bool IsValid(int x, int y)
{
	if (x >= 0 && x < w + 2 && y >= 0 && y < h + 2 && !visited[y][x] && (map[y][x] == '.' || map[y][x] == '$' || (map[y][x] >= 'a' && map[y][x] <= 'z')))
		return true;
	return false;
}

void DFS(int x, int y)
{
	visited[y][x] = true;
	if (map[y][x] >= 'a' && map[y][x] <= 'z')
	{
		OpenDoor(map[y][x]);
		visited[y][x] = true;
		map[y][x] = '.';
	}
	else if (map[y][x] == '$')
	{
		ans++;
		map[y][x] = '.';
		VisitedInit();
		visited[y][x] = true;
	}
	for (int i = 0; i < 4; i++)
	{
		int NextX = x + dx[i];
		int NextY = y + dy[i];
		if (IsValid(NextX, NextY))
			DFS(NextX, NextY);
	}
}