#include <iostream>
#define MAX 10
#define BLACK 0
#define WHITE 1

using namespace std;
int n, ans[2];
int map[MAX][MAX];
bool leftDiagonal[MAX * 2];
bool rightDiagonal[MAX * 2];

void backtracking(int y, int x, int count, int color);
void init();

int main()
{
	init();
	backtracking(0, 0, 0, BLACK);
	backtracking(0, 1, 0, WHITE);
	cout << ans[BLACK] + ans[WHITE];
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void backtracking(int y, int x, int count, int color)
{
	if (x >= n)
	{
		y++;
		if (x % 2 == 0) x = 1;
		else x = 0;
	}
	if (y >= n)
	{
		ans[color] = max(ans[color], count);
		return;
	}
	if (map[y][x] && !leftDiagonal[x - y + n - 1] && !rightDiagonal[x + y])
	{
		leftDiagonal[x - y + n - 1] = true;
		rightDiagonal[x + y] = true;
		backtracking(y, x + 2, count + 1, color);
		leftDiagonal[x - y + n - 1] = false;
		rightDiagonal[x + y] = false;
	}
	backtracking(y, x + 2, count, color);
}