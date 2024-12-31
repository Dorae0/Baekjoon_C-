#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, x, y;

map < pair<int, int>, bool > mp_upper;
map < pair<int, int>, bool > mp_lower;

void init();
int gcd(int a, int b);

int main()
{
	init();
	cout << mp_upper.size() + mp_lower.size();
}

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		int currentGCD = 0;
		if (y)
			currentGCD = gcd(x, y);
		if (x == 0)
		{
			if (y > 0)
				mp_upper[{0, 1}] = true;
			else
				mp_lower[{0, -1}] = true;
		}
		else if (y == 0)
		{
			if (x > 0)
				mp_upper[{1, 0}] = true;
			else
				mp_lower[{-1, 0}] = true;
		}
		else
		{
			if (y > 0)
				mp_upper[{x / currentGCD, y / currentGCD}] = true;
			else if (y < 0)
				mp_lower[{x / currentGCD, y / currentGCD}] = true;
		}
	}
}