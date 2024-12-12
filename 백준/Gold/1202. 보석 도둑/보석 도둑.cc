#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using pll = pair<long long, long long>;

long long n, k, m, v, c, ans;
vector<pll> jewels;
vector<long long> bags;
priority_queue<pll> pq;

void init();
void takeJewel();

int main()
{
	init();
	takeJewel();
	cout << ans;
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewels.push_back({m, v});
	}
	sort(jewels.begin(), jewels.end());
	for(int i = 0; i < k; i++)
	{
		cin >> c;
		bags.push_back(c);
	}
	sort(bags.begin(), bags.end());
}

void takeJewel()
{
	int jewelIdx = 0;
	for(int i = 0; i < bags.size(); i++)
	{
		while(bags[i] >= jewels[jewelIdx].first && jewelIdx < jewels.size())
		{
			pq.push({jewels[jewelIdx].second, jewels[jewelIdx].first});
			jewelIdx++;
		}
		if(pq.empty())
			continue;
		if(pq.top().second <= bags[i])
		{
			ans += pq.top().first;
			pq.pop();
		}
	}
}