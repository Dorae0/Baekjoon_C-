#include <iostream>

#define MAX 101
#define WEIGHT_MAX 10001

using namespace std;
int n, m, weight_sum;
int memory[MAX];
int weight[MAX];
int dp[MAX][WEIGHT_MAX];

void init();
void DP();

int main()
{
	init();
	DP();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> memory[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> weight[i];
		weight_sum += weight[i];
	}
}

void DP()
{
	for(int i = 1; i <= n; i++)
	{
		int currentWeight = weight[i];
		int currentMemory = memory[i];
		for(int j = 0; j <= weight_sum; j++)
		{
			if(j >= currentWeight)
				dp[i][j] = max(max(dp[i - 1][j], dp[i][max(0, j - 1)]), dp[i - 1][max(0, j - currentWeight)] + currentMemory);
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][max(0, j - 1)]);
			if(i == n && dp[i][j] >= m)
			{
				cout << j;
				return;
			}
		}
	}
}