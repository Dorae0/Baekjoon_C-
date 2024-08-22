#include <iostream>
#include <algorithm>
#define MAX 10

using namespace std;
int map[MAX][MAX];
int paper_left[5] = { 5, 5, 5, 5, 5 };
int ans = 100;

int checksize(int x, int y);
void paper_change(int x, int y, int size, int num);
void solve(int x, int y, int currentNum);

int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> map[i][j];
	solve(0, 0, 0);
	if (ans == 100) cout << -1;
	else cout << ans;
	return 0;
}

int checksize(int x, int y)
{
	int count = 1;
	for (count = 1; count <= 5; count++)
	{
		for (int i = 0; i < count; i++)
		{
			if (x + count - 1 >= MAX || y + count - 1 >= MAX)
				return count - 1;
			if (map[y + i][x + count - 1] == 0 || map[y + count - 1][x + i] == 0)
				return count - 1;
		}
	}
	return 5;
}

void paper_change(int x, int y, int size, int num)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			map[y + i][x + j] = num;
}

void solve(int x, int y, int currentNum)
{
	while (y < 10)
	{
		while (x < 10)
		{
			if (map[y][x] == 1) break;
			x++;
		}
		if (x == 10)
		{
			x = 0;
			y++;
		}
		if (map[y][x] == 1) break;
	}
		
	if (y == 10)
	{
		ans = min(ans, currentNum);
		return;
	}

	if (ans <= currentNum)
		return;

	int papersize = checksize(x, y);
	for (int i = papersize; i >= 1; i--)
	{
		if (paper_left[i - 1])
		{
			paper_change(x, y, i, 0);
			paper_left[i - 1]--;
			solve(x, y, currentNum + 1);
			paper_change(x, y, i, 1);
			paper_left[i - 1]++;
		}
	}
}