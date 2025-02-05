#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int k, n, c;
vector<int> vOdd, vEven;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Init();
void GetAnswer();

int main()
{
	Init();
	GetAnswer();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> c;
		pq.push({ c, i });
	}
}

void GetAnswer()
{
	while (!pq.empty())
	{
		int CurrentVal = pq.top().first;
		if (CurrentVal > ceil((double)n / 2))
		{
			cout << -1;
			return;
		}
		int CurrentNum = pq.top().second;
		pq.pop();
		for (int i = 0; i < CurrentVal; i++)
		{
			if (vEven.size() < n / 2)
				vEven.push_back(CurrentNum);
			else
				vOdd.push_back(CurrentNum);
		}
	}
	for (int i = 0; i < vEven.size(); i++)
		cout << vOdd[i] << ' ' << vEven[i] << ' ';
	if (n % 2)
		cout << vOdd[vOdd.size() - 1];
}