#include <iostream>
#include <string>
#include <queue>
#define MAX 1000

using namespace std;
int n, m, ans;
char map[MAX][MAX];
pair<int, int> parent[MAX][MAX];
int ansMap[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

void Init();
void Union(pair<int, int> x, pair<int, int> y);
pair<int, int> Find(pair<int, int> x);
bool IsValid(int y, int x);
void SafeZone();

int main()
{
	Init();
	SafeZone();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			parent[i][j] = { i, j };
}

void Union(pair<int, int> x, pair<int, int> y)
{
	x = Find(x); y = Find(y);
	if (x.first > y.first || x.first == y.first && x.second > y.second)
		swap(x, y);
	parent[y.first][y.second] = { x.first, x.second };
}

pair<int, int> Find(pair<int, int> x)
{
	if (x == parent[x.first][x.second])
		return x;
	return parent[x.first][x.second] = Find(parent[x.first][x.second]);
}

bool IsValid(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}

void SafeZone()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j])
			{
				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> currentPos = q.front();
					q.pop();
					visited[currentPos.first][currentPos.second] = true;
					switch (map[currentPos.first][currentPos.second])
					{
					case 'U':
						if (IsValid(currentPos.first - 1, currentPos.second))
						{
							if (visited[currentPos.first - 1][currentPos.second])
							{
								if (Find(currentPos) == Find({ currentPos.first - 1, currentPos.second }))
									while (!q.empty()) q.pop();
								else
									Union(currentPos, { currentPos.first - 1, currentPos.second });
							}
							else
							{
								q.push({ currentPos.first - 1, currentPos.second });
								Union(currentPos, { currentPos.first - 1, currentPos.second });
							}
						}
						break;
					case 'D':
						if (IsValid(currentPos.first + 1, currentPos.second))
						{
							if (visited[currentPos.first + 1][currentPos.second])
							{
								if (Find(currentPos) == Find({ currentPos.first + 1, currentPos.second }))
									while (!q.empty()) q.pop();
								else
									Union(currentPos, { currentPos.first + 1, currentPos.second });
							}
							else
							{
								q.push({ currentPos.first + 1, currentPos.second });
								Union(currentPos, { currentPos.first + 1, currentPos.second });
							}
						}
						break;
					case 'L':
						if (IsValid(currentPos.first, currentPos.second - 1))
						{
							if (visited[currentPos.first][currentPos.second - 1])
							{
								if (Find(currentPos) == Find({ currentPos.first, currentPos.second - 1 }))
									while (!q.empty()) q.pop();
								else
									Union(currentPos, { currentPos.first, currentPos.second - 1});
							}
							else
							{
								q.push({ currentPos.first, currentPos.second - 1 });
								Union(currentPos, { currentPos.first, currentPos.second - 1 });
							}
						}
						break;
					case 'R':
						if (IsValid(currentPos.first, currentPos.second + 1))
						{
							if (visited[currentPos.first][currentPos.second + 1])
							{
								if (Find(currentPos) == Find({ currentPos.first, currentPos.second + 1 }))
									while (!q.empty()) q.pop();
								else
									Union(currentPos, { currentPos.first, currentPos.second + 1 });
							}
							else
							{
								q.push({ currentPos.first, currentPos.second + 1 });
								Union(currentPos, { currentPos.first, currentPos.second + 1 });
							}
						}
						break;
					}
				}
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			pair<int, int> currentParent = Find(parent[i][j]);
			if (ansMap[currentParent.first][currentParent.second]++ == 0)
				ans++;
		}

	cout << ans;
}