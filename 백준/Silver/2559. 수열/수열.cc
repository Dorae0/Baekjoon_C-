#include <iostream>
#include <vector>

using namespace std;
int n, k, temp;
vector<int> v;

void init();
void prefixSum();

int main()
{
	init();
	prefixSum();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	v.push_back(0);
	for(int i = 1; i <= n; i++)
	{
		cin >> temp;
		v.push_back(temp + v[i - 1]);
	}
}

void prefixSum()
{
	int max_val = -2'000'000'000;
	for(int i = k; i <= n; i++)
		max_val = max(max_val, v[i] - v[i - k]);
	cout << max_val;
}