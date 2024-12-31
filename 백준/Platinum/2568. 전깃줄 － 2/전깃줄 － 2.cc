#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, startNode, endNode;
bool isChecked;

vector<pii> vec;
vector<int> v;
vector<int> dp;
vector<int> answer;

void init();
void LIS();
void backtracking(int currentNum, int currentIdx);

int main()
{
	init();
	LIS();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> startNode >> endNode;
		vec.push_back({ startNode, endNode });
	}
	sort(vec.begin(), vec.end());
}

void LIS()
{
	v.push_back(0);
	for(int i = 0; i < n; i++)
	{
		int currentNum = vec[i].second;
		if (v.back() < currentNum)
		{
			v.push_back(currentNum);
			dp.push_back(v.size() - 1);
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), currentNum);
			*it = currentNum;
			dp.push_back(it - v.begin());
		}
	}
	backtracking(v.size() - 1, n - 1);
	cout << vec.size() - answer.size() << '\n';

	int answerIdx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second != answer[answerIdx])
			cout << vec[i].first << '\n';
		else
			answerIdx++;
	}
}

void backtracking(int currentNum, int currentIdx)
{
	if (currentNum == 0)
	{
		isChecked = true;
		reverse(answer.begin(), answer.end());
		return;
	}
	for (int i = currentIdx; i >= 0; i--)
	{
		if (isChecked)
			return;
		if (dp[i] == currentNum)
		{
			answer.push_back(vec[i].second);
			backtracking(currentNum - 1, i);
		}
	}
}