#include <iostream>
#include <algorithm>

using namespace std;

int n;

int RGB[1000][3];
int dp[1001][3];

void RGBInit()
{
	for (int i = 0; i < n; i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	return;
}

void makeDP()
{
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = RGB[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = RGB[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = RGB[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
}

int main()
{
	cin >> n;
	RGBInit();
	for (int i = 0; i < 3; i++) dp[0][i] = RGB[0][i];
	makeDP();

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}