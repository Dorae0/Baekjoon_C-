#include <iostream>
#define MAX 1000

using namespace std;
int m, n, x;
long long modulo[1000];
long long sum, ans;

void Init();
void Solve();

int main()
{
	Init();
	Solve();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
		modulo[sum % m]++;
	}
}

void Solve()
{
	for (int i = 0; i < 1000; i++)
		ans += modulo[i] * (modulo[i] - 1) / 2;
	cout << modulo[0] + ans;
}