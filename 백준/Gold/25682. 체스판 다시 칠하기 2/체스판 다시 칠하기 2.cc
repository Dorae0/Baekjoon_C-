#include <iostream>
#include <algorithm>

#define INF ~0U >> 2
#define MAX 2001
#define BLACK false
#define WHITE true

using namespace std;
int n, m, k;
int ans = INF;
char map[MAX][MAX];
int pMap[MAX][MAX];

void Init();
bool Check(int x, int y, char color);
void PrefixSum();
void Solve();

int main()
{
	Init();
	PrefixSum();
	Solve();
}

void Init()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> (map[i] + 1);
}

bool Check(int x, int y, char color)
{
	bool colorCheck;
	if (color == 'B')
		colorCheck = BLACK;
	else
		colorCheck = WHITE;
	if ((x + y) % 2 == colorCheck)
		return true;
	return false;
}

void PrefixSum()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (Check(i, j, map[i][j]))
				pMap[i][j] = pMap[i][j - 1] + 1;
			else
				pMap[i][j] = pMap[i][j - 1];
		}

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pMap[i][j] += pMap[i - 1][j];
}

void Solve()
{
	for (int i = 1; i <= n - k + 1; i++)
		for (int j = 1; j <= m - k + 1; j++)
		{
			int currentAns = pMap[i + k - 1][j + k - 1] - pMap[i - 1][j + k - 1] - pMap[i + k - 1][j - 1] + pMap[i - 1][j - 1];
			currentAns = min(currentAns, k * k - currentAns);
			ans = min(ans, currentAns);
		}

	cout << ans;
}