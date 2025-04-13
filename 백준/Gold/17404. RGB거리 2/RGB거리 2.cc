#include <iostream>
#include <algorithm>

#define MAX 1001
#define INF ~0U >> 2

using namespace std;

int n, ans = INF;

int RGB[MAX][3];
int dp[MAX][3];

void Init();
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
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
}

void DP()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (i == j)
				dp[1][j] = RGB[1][j];
			else
				dp[1][j] = INF;
		}
		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = RGB[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = RGB[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = RGB[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}
		for (int j = 0; j <= 2; j++)
			if (i != j)
				ans = min(ans, dp[n][j]);
	}

	cout << ans;
}