#include <iostream>

using namespace std;
int n, m;

void init();
void solve();

int main()
{
	init();
	solve();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
}

void solve()
{
	if (n % 2 == 0 || m % 2 == 0)
		cout << 'A';
	else
		cout << 'B';
}