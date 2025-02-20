#include <iostream>
#define DIVIDER 1'000'000'007

using namespace std;

int n;
long long dp[1516][3];

void Init();
void DP();

int main()
{
	Init();
	DP();
	cout << dp[n][0];
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void DP()
{
	dp[1][2] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			dp[i][j] = (dp[i - 1][(j + 1) % 3] + dp[i - 1][(j + 2) % 3]) % DIVIDER;
	}
}