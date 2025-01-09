#include <iostream>

using namespace std;
int n;

void init();
void nQueen();

int main()
{
	init();
	nQueen();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void nQueen()
{
	if (n % 6 == 2)
	{
		for (int i = 2; i <= n; i += 2)
			cout << i << '\n';
		cout << 3 << '\n' << 1 << '\n';
		for (int i = 7; i <= n; i += 2)
			cout << i << '\n';
		cout << 2;
	}
	else if (n % 6 == 3)
	{
		for (int i = 4; i <= n; i += 2)
			cout << i << '\n';
		cout << 2 << '\n';
		for (int i = 5; i <= n; i += 2)
			cout << i << '\n';
		cout << 1 << '\n' << 3 << '\n';
	}
	else
	{
		for (int i = n / 2; i > 0; i--)
			cout << i << '\n' << i + n / 2 << '\n';
		if (n % 2 == 1)
			cout << n;
	}
}