#include <iostream>
#include <string>

#define MAX 2500
#define INF ~0U >> 2

using namespace std;

string s;
bool dp[MAX][MAX];
int pCount[MAX];

void Init();
void DP();

int main()
{
	Init();
	DP();
	cout << pCount[s.length() - 1];
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		pCount[i] = INF;
}

void DP()
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		dp[i][i] = true;
		if (s[i] == s[i + 1])
			dp[i][i + 1] = true;
	}
	dp[s.length() - 1][s.length() - 1] = 1;

	for (int i = 0; i < s.length(); i++)
	{
		int startIdx = i;
		int endIdx = i;
		while (--startIdx >= 0 && ++endIdx < s.length())
		{
			if (dp[startIdx + 1][endIdx - 1] && s[startIdx] == s[endIdx])
				dp[startIdx][endIdx] = true;
			else break;
		}
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
		int startIdx = i;
		int endIdx = i + 1;
		while (--startIdx >= 0 && ++endIdx < s.length())
		{
			if (dp[startIdx + 1][endIdx - 1] && s[startIdx] == s[endIdx])
				dp[startIdx][endIdx] = true;
			else break;
		}
	}

	pCount[0] = 1;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (dp[j][i])
			{
				if (j == 0)
					pCount[i] = min(pCount[i], 1);
				else
					pCount[i] = min(pCount[i], pCount[j - 1] + 1);
			}
		}
	}
}