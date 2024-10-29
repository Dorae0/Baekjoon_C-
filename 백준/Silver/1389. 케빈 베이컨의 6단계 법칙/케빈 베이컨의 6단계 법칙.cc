#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

#define MAX 100 + 1
using namespace std;

int GraphMap[MAX][MAX];
int visited[MAX];
int answer[MAX];
int Ans = 2000000000;
int AnsIdx;
int n, m, tempx, tempy;

queue<int> q;

void ArrInit();
int bfs(int n);

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tempx >> tempy;
		GraphMap[tempx][tempy] = 1;
		GraphMap[tempy][tempx] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		ArrInit();
		answer[i] = bfs(i);
	}

	for (int i = n; i > 0; i--)
		if (Ans >= answer[i])
		{
			Ans = answer[i];
			AnsIdx = i;
		}

	cout << AnsIdx;

	return 0;
}

int bfs(int n)
{
	int answer = 0;
	q.push(n);
	while (!q.empty())
	{
		int currentX = q.front(); // currentX : q에서 빠질 자리.
		q.pop(); // pop
		for (int i = 1; i <= ::n; i++)
		{
			if (currentX == i) // 겹치면 continue
				continue;
			if (GraphMap[currentX][i] == 1 && visited[i] == 0) // GraphMap 자리가 1이고 visited가 0이라면
			{
				q.push(i);
				visited[i] = visited[currentX] + 1; // visited = visited[currentX] + 1;
			}
		}
	}
	for (int i = 1; i <= ::n; i++)
	{
		if (i == n)
			continue;
		answer += visited[i];
	}
	return answer;
}

void ArrInit()
{
	for (int i = 0; i < MAX; i++) visited[i] = 0;
}