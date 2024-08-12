#include <iostream>
using namespace std;

int t, m, n, x, y;

int gcd(int a, int b);
int countnum(int m, int n, int x, int y);

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> x >> y;
		cout << countnum(m, n, x, y) << endl;
	}
	return 0;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int countnum(int m, int n, int x, int y)
{
	int cur_gcd = gcd(m, n);
	int cur_lcm = m * n / cur_gcd;
	if (abs(x - y) % cur_gcd)
		return -1;
	while (x <= cur_lcm && y <= cur_lcm)
	{
		if (x < y) x += m;
		else if (x > y) y += n;
		else return x;
	}
}