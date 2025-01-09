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
	for (int i = n / 2; i > 0; i--)
		cout << i << '\n' << i + n / 2 << '\n';
	if (n % 2 == 1)
		cout << n;
}