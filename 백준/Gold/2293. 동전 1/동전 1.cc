#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
#define NUM_MAX 10001

using namespace std;

void Init();
int n, k, temp;
long long dp[NUM_MAX][2];

vector<int> v;

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
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
}

void DP()
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i == 0)
			{
				if (j % v[i] == 0)
					dp[j][i % 2]++;
			}
			else
			{
				dp[j][i % 2] = dp[j][(i + 1) % 2];
				if (j == v[i])
					dp[j][i % 2]++;
				dp[j][i % 2] += dp[max(0, j - v[i])][i % 2];
			}
		}
	}
	cout << dp[k][(v.size() - 1) % 2];
}