#include <iostream>
#include <algorithm>

#define MAX 501
#define INF ~0U >> 2

using namespace std;

int t, k, n;
int numbers[MAX];
int dp[MAX][MAX];

void Init();
void Solve();
void Input();
void DP();

int main()
{
	Init();
	Solve();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
}

void Solve()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		Input();
		DP();
	}
}

void Input()
{
	cin >> k;
	int currentN = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> n;
		currentN += n;
		numbers[i] = currentN;
	}
}

void DP()
{
	for (int i = 0; i < k - 1; i++)
		dp[i][i + 1] = numbers[i + 2] - numbers[i];
	for (int i = 2; i <= k - 1; i++)
	{
		for (int j = 0; i + j <= k - 1; j++)
		{
			int currentMin = INF;
			for (int l = j; l < i + j; l++)
				currentMin = min(currentMin, dp[j][l] + dp[l + 1][i + j]);
			dp[j][i + j] = currentMin + numbers[i + j + 1] - numbers[j];
		}
	}

	cout << dp[0][k - 1] << '\n';
}