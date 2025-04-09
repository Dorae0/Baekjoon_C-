#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 4'000'000

using namespace std;
int n, ans;
bool prime[MAX + 1];
vector<long long> primePrefixSum;

void Init();
void MakePrime();
void Solve();

int main()
{
	Init();
	MakePrime();
	Solve();
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; i++)
		prime[i] = true;
}

void MakePrime()
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!prime[i]) continue;
		for (int j = i * i; j <= n; j += i)
			prime[j] = false;
	}

	primePrefixSum.push_back(0);

	for (int i = 1; i <= n; i++)
	{
		if (prime[i])
			primePrefixSum.push_back(i + primePrefixSum[primePrefixSum.size() - 1]);
	}
}

void Solve()
{
	for (int i = 0; i < primePrefixSum.size(); i++)
	{
		if (primePrefixSum[i] < n) continue;
		else if (binary_search(primePrefixSum.begin(), primePrefixSum.end(), primePrefixSum[i] - n))
			ans++;
	}
}