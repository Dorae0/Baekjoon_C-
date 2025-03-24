#include <iostream>
#define DIVIDER 1'000'000'007

using namespace std;

int n, k;
long long a = 1, b = 1;

void Init();
long long Power(long long x);
long long Combination(int n, int k);

int main()
{
	Init();
	cout << Combination(n, k) % DIVIDER;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	k = min(k, n - k);
}

long long Power(long long x)
{
	if (x == 0) return 1;

	if (x % 2 == 1)
		return b * Power(x - 1) % DIVIDER;
	long long half = Power(x / 2);
	return half * half % DIVIDER;
}

long long Combination(int n, int k)
{
	if (n == 0 || k == 0 || n == k) return 1;

	for (int i = n; i >= n - k + 1; i--)
		a = (a * i) % DIVIDER;
	for (int i = 1; i <= k; i++)
		b = (b * i) % DIVIDER;

	b = Power(DIVIDER - 2);

	return a * b % DIVIDER;
} 