#include <iostream>
#include <cmath>

using namespace std;
int t, x, y;

void init();
void cultivator();

int main()
{
	init();
	cultivator();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
}

void cultivator()
{
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y;
		int xLog = log2(x + 1) + 1;
		int yLog = log2(y + 1) + 1;
		int sumLog = log2(x + y + 1) + 1;
		int ans = 0;
		ans += pow(2, min(xLog, yLog)) - 1;
		ans += (min(x, y) + 1) * (abs(xLog - yLog));
		if (sumLog > max(xLog, yLog))
			ans += (x + y) - pow(2, sumLog - 1) + 2;
		cout << ans << '\n';
	}
}