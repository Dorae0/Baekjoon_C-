#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#define MAX 20

using namespace std;
int r, c, ans = 0;
string char_map[MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ischecked[26];

bool IsMoveable(int x, int y);
void move(int x, int y, int count);

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> char_map[i];
	ischecked[char_map[0][0] - 'A']++;
	move(0, 0, 0);
	cout << ans;
}

bool IsMoveable(int x, int y)
{
	if (x < 0 || y < 0 || x >= c || y >= r)
		return false;
	return true;
}

void move(int x, int y, int count)
{
	if (ischecked[char_map[y][x] - 'A'] >= 2)
	{
		ans = max(ans, count);
		return;
	}
	else count++;
	for (int i = 0; i < 4; i++)
	{
		if (IsMoveable(x + dx[i], y + dy[i]))
		{
			ischecked[char_map[y + dy[i]][x + dx[i]] - 'A']++;
			move(x + dx[i], y + dy[i], count);
			ischecked[char_map[y + dy[i]][x + dx[i]] - 'A']--;
		}
	}
	ans = max(ans, count);
}