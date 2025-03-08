#include <iostream>
#include <set>
#define MAX 30

using namespace std;
int x, y;
int weights[MAX];
int checks[7];
set<int> s, sNew;

void Init();
void DP();
void Solve();

int main()
{
	Init();
	DP();
	Solve();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> x;
	for (int i = 0; i < x; i++)
		cin >> weights[i];
	cin >> y;
	for (int i = 0; i < y; i++)
		cin >> checks[i];
}

void DP()
{
	for (int i = 0; i < x; i++)
	{
		sNew.insert(weights[i]);
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (*it + weights[i] <= 40000)
				sNew.insert(*it + weights[i]);
			if (weights[i] - *it > 0 && weights[i] - *it <= 40000)
				sNew.insert(weights[i] - *it);
			if (*it - weights[i] > 0 && *it - weights[i] <= 40000)
				sNew.insert(*it - weights[i]);
		}
		s = sNew;
	}
}

void Solve()
{
	for (int i = 0; i < y; i++)
	{
		if (s.find(checks[i]) == s.end())
			cout << "N ";
		else
			cout << "Y ";
	}
}