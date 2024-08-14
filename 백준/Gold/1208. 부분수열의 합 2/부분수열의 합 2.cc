#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 40
#define HALF_MAX MAX / 2

using namespace std;

int n, s;
long long ans = 0;
int left_arr[HALF_MAX], right_arr[HALF_MAX];
map<int, int> mp;

void leftSumInit(int curNum, int curSum);
void rightSumInit(int curNum, int curSum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			cin >> left_arr[i];
		else
			cin >> right_arr[i - n / 2];
	}
	leftSumInit(0, 0);
	rightSumInit(0, 0);
	if (s == 0) ans--;
	cout << ans;
}

void leftSumInit(int curNum, int curSum)
{
	if (curNum == n / 2)
	{
		mp[curSum]++;
		return;
	}
	leftSumInit(curNum + 1, curSum + left_arr[curNum]);
	leftSumInit(curNum + 1, curSum);
}

void rightSumInit(int curNum, int curSum)
{
	if (curNum == n - n / 2)
	{
		ans += mp[s - curSum];
		return;
	}
	rightSumInit(curNum + 1, curSum + right_arr[curNum]);
	rightSumInit(curNum + 1, curSum);
}