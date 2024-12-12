#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pll = pair<long long , long long>;

long long n;
long long temp;
vector<long long> dist;
vector<pll> value;

void init();
void gas_station();

int main()
{
	init();
	gas_station();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> temp;
		dist.push_back(temp);
	}
	for(int i = 0; i < n - 1; i++)
	{
		cin >> temp;
		value.push_back({temp, i});
	}
	cin >> temp;
	sort(value.begin(), value.end());
}

void gas_station()
{
	long long ans = 0;
	long long currentPos = n - 1;
	long long valueIdx = -1;
	while(++valueIdx < n - 1)
	{
		long long currentVal = value[valueIdx].first;
		long long currentIdx = value[valueIdx].second;
		if(currentPos >= currentIdx)
		{
			for(long long i = currentIdx; i < currentPos; i++)
				ans += currentVal * dist[i];
			currentPos = currentIdx;
		}
	}
	cout << ans;
}