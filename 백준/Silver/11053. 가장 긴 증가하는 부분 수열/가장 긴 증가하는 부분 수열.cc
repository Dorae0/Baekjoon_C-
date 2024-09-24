#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int numDatabase[1001] = { 0, };
int dp[1001] = { 0, };
int numbersCount = 0;

void dpInit();
void Solution();
int Calculate();
void Print();

int main()
{
	dpInit();
	Solution();
	Print();
	return 0;
}

void dpInit()
{
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)
	{
		cin >> numDatabase[i];
		dp[i] = 1;
	}
}

void Solution()
{
	for (int i = 1; i < numbersCount; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numDatabase[i] > numDatabase[j])
			{
				dp[i] = dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i];
			}
		}
	}
}

int Calculate()
{
	int answer = 0;
	for (int i = 0; i < numbersCount; i++)
		answer = answer > dp[i] ? answer : dp[i];
	return answer;
}

void Print()
{
	cout << Calculate();
}