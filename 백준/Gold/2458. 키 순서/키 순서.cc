#include <iostream>
#define INF ~0U >> 2
#define MAX 501

using namespace std;
int n, m, startNode, endNode;
int map[MAX][MAX];

void Init();
void Floyd_Warshall();
bool Check(int nodeNum);

int main()
{
	int ans = 0;
	Init();
	Floyd_Warshall();
	for (int i = 1; i <= n; i++)
		if (Check(i)) ans++;
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	for (int i = 0; i < m; i++)
	{
		cin >> startNode >> endNode;
		map[startNode][endNode] = 1;
	}
}

void Floyd_Warshall()
{
	for (int node = 1; node <= n; node++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][node] != INF && map[node][j] != INF)
					map[i][j] = 1; // 가능
}

bool Check(int nodeNum)
{
	for (int i = 1; i <= n; i++)
		if (map[nodeNum][i] == INF && map[i][nodeNum] == INF)
			return false;
	return true;
}