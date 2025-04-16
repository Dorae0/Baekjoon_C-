#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100'001
#define INF ~0U >> 2

using namespace std;

int temp, ans = INF;
int firstFoot[10] ={ 0, 0, 0, 0, 1, 1, 1, 2, 2, 3 };
int secondFoot[10] = { 1, 2, 3, 4, 2, 3, 4, 3, 4, 4 };
int dp[MAX][10];
vector<int> order;

void Init();
int GetNum(int x, int y);
void DP();

int main()
{
	Init();
	DP();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	while (1)
	{
		cin >> temp;
		if (!temp) break;
		order.push_back(temp);
	}
	for (int i = 0; i < order.size(); i++)
		for (int j = 0; j < 10; j++)
			dp[i][j] = INF;
}

int GetNum(int x, int y)
{
	if (x > y) swap(x, y);
	int ret = y;
	switch (x)
	{
	case 3:
		ret += 1;
	case 2:
		ret += 2;
	case 1:
		ret += 3;
	case 0:
		ret--;
		break;
	}
	return ret;
}

void DP()
{
	if (order.size() == 0)
	{
		cout << 0;
		return;
	}

	dp[0][order[0] - 1] = 2;

	for (int i = 0; i < order.size() - 1; i++)
	{
		int currentOrder = order[i + 1];
		for (int j = 0; j < 10; j++)
		{
			if (dp[i][j] == INF) continue;
			if (firstFoot[j] == currentOrder || secondFoot[j] == currentOrder)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			else
			{
				int firstDestination = GetNum(firstFoot[j], currentOrder);
				if(secondFoot[j] == 0)
					dp[i + 1][firstDestination] = min(dp[i + 1][firstDestination], dp[i][j] + 2);
				else if (abs(secondFoot[j] - currentOrder) != 2)
					dp[i + 1][firstDestination] = min(dp[i + 1][firstDestination], dp[i][j] + 3);
				else
					dp[i + 1][firstDestination] = min(dp[i + 1][firstDestination], dp[i][j] + 4);

				int secondDestination = GetNum(secondFoot[j], currentOrder);
				if (firstFoot[j] == 0)
					dp[i + 1][secondDestination] = min(dp[i + 1][secondDestination], dp[i][j] + 2);
				else if (abs(firstFoot[j] - currentOrder) != 2)
					dp[i + 1][secondDestination] = min(dp[i + 1][secondDestination], dp[i][j] + 3);
				else
					dp[i + 1][secondDestination] = min(dp[i + 1][secondDestination], dp[i][j] + 4);
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = min(ans, dp[order.size() - 1][i]);
	cout << ans;
}