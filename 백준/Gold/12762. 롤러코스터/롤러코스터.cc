#include <iostream>
#define MAX 1000
#define ASC 0
#define DESC 1

using namespace std;

int n, ans;
int numbers[MAX];
int dp[MAX][2];

void Init();
void DP();

int main()
{
	Init();
	DP();
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
}

void DP()
{
	for(int i = 0; i < n; i++)
		dp[i][DESC] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (numbers[i] < numbers[j])
				dp[i][DESC] = max(dp[i][DESC], dp[j][DESC] + 1);

	for (int i = 0; i < n; i++)
		dp[i][ASC] = 1;

	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j > i; j--)
			if (numbers[i] < numbers[j])
				dp[i][ASC] = max(dp[i][ASC], dp[j][ASC] + 1);

	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i][DESC] + dp[i][ASC] - 1);
}