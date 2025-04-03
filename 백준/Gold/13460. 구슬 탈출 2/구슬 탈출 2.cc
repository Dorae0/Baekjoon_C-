#include <iostream>
#include <queue>

#define MAX 10
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;
int n, m, ans = -1;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pair<int, int> initR, initB;
char map[MAX][MAX];

void Init();
void MarbleGame();
bool MoveMarbleR(int direction, pair<int, int> r, pair<int, int> b, pair<int, int>* newR);
bool MoveMarbleB(int direction, pair<int, int> b, pair<int, int> r, pair<int, int>* newB);

struct Sdata {
	int count;
	pair<int, int>r, b;
};
queue<Sdata> q;

int main()
{
	Init();
	q.push(Sdata{ 1, initR, initB });
	MarbleGame();
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				initR.first = j;
				initR.second = i;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B')
			{
				initB.first = j;
				initB.second = i;
				map[i][j] = '.';
			}
		}
}

bool MoveMarbleR(int direction, pair<int, int> r, pair<int, int> b, pair<int, int>* newR)
{
	while (1)
	{
		if (map[r.second + dy[direction]][r.first + dx[direction]] == '#' || r.second + dy[direction] == b.second && r.first + dx[direction] == b.first)
		{
			newR->first = r.first;
			newR->second = r.second;
			return false;
		}
		if (map[r.second + dy[direction]][r.first + dx[direction]] == '.')
		{
			r.first += dx[direction];
			r.second += dy[direction];
		}
		if (map[r.second + dy[direction]][r.first + dx[direction]] == 'O')
		{
			newR->first = -1;
			newR->second = -1;
			return true;
		}
	}
}

bool MoveMarbleB(int direction, pair<int, int> b, pair<int, int> r, pair<int, int>* newB)
{
	while (1)
	{
		if (map[b.second + dy[direction]][b.first + dx[direction]] == '#' || b.second + dy[direction] == r.second && b.first + dx[direction] == r.first)
		{
			newB->first = b.first;
			newB->second = b.second;
			return false;
		}
		if (map[b.second + dy[direction]][b.first + dx[direction]] == '.')
		{
			b.first += dx[direction];
			b.second += dy[direction];
		}
		if (map[b.second + dy[direction]][b.first + dx[direction]] == 'O')
		{
			newB->first = -1;
			newB->second = -1;
			return true;
		}
	}
}

void MarbleGame()
{
	while (!q.empty())
	{
		int count = q.front().count;
		pair<int, int> r = q.front().r;
		pair<int, int> b = q.front().b;
		q.pop();
		if (b.first == -1 && b.second == -1)
			return;
		if (count > 10 || ans > 0)
			return;
		for (int i = LEFT; i <= DOWN; i++)
		{
			pair<int, int> newR;
			pair<int, int> newB;
			bool resultR = false;
			bool resultB = false;
			switch (i)
			{
			case LEFT:
				if (r.second == b.second && r.first < b.first)
				{
					resultR = MoveMarbleR(i, r, b, &newR);
					resultB = MoveMarbleB(i, b, newR, &newB);
				}
				else
				{
					resultB = MoveMarbleB(i, b, r, &newB);
					resultR = MoveMarbleR(i, r, newB, &newR);
				}
				break;
			case RIGHT:
				if (r.second == b.second && r.first > b.first)
				{
					resultR = MoveMarbleR(i, r, b, &newR);
					resultB = MoveMarbleB(i, b, newR, &newB);
				}
				else
				{
					resultB = MoveMarbleB(i, b, r, &newB);
					resultR = MoveMarbleR(i, r, newB, &newR);
				}
				break;
			case UP:
				if (r.first == b.first && r.second < b.second)
				{
					resultR = MoveMarbleR(i, r, b, &newR);
					resultB = MoveMarbleB(i, b, newR, &newB);
				}
				else
				{
					resultB = MoveMarbleB(i, b, r, &newB);
					resultR = MoveMarbleR(i, r, newB, &newR);
				}
				break;
			case DOWN:
				if (r.first == b.first && r.second > b.second)
				{
					resultR = MoveMarbleR(i, r, b, &newR); 
					resultB = MoveMarbleB(i, b, newR, &newB);
				}
				else
				{
					resultB = MoveMarbleB(i, b, r, &newB);
					resultR = MoveMarbleR(i, r, newB, &newR);
				}
				break;
			}
			if (!resultB && resultR)
			{
				ans = count;
				return;
			}
			if(!resultB && !resultR)
				q.push(Sdata{count + 1, newR, newB});
		}
	}
}