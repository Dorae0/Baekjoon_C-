#include <iostream>
#include <cmath>
#define MAX 1'000'001

using namespace std;

long long minN, maxN;
bool prime[MAX];
bool squarePrime[MAX];

void Init();
void PrimeInit();
void GetSquarePrime();

int main()
{
	Init();
	GetSquarePrime();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> minN >> maxN;
	PrimeInit();
}

void PrimeInit()
{
	for (int i = 2; i < MAX; i++)
		prime[i] = true;
	for (int i = 2; i < sqrt(MAX); i++)
	{
		if (!prime[i]) continue;
		for (int j = i * i; j < MAX; j += i)
			prime[j] = false;
	}
}

void GetSquarePrime()
{
	for (long long i = 0; i < maxN - minN + 1; i++)
		squarePrime[i] = true;
	for (long long i = 2; i <= sqrt(maxN); i++)
	{
		if (!prime[i]) continue;
		long long currentDivider = i * i;
		if (currentDivider > maxN) continue;

		long long startNum = ceil((double)minN / currentDivider) * currentDivider;

		for (long long j = startNum; j <= maxN; j += currentDivider)
			squarePrime[j - minN] = false;
	}
	long long ans = 0;
	for (long long i = 0; i < maxN - minN + 1; i++)
		if (squarePrime[i]) ans++;
	cout << ans;
}