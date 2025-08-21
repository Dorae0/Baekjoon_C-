#include <iostream>
#include <cmath>
#define MAX 1'000'000'000

using namespace std;

int x, y, z, ans;

void Init();
void CheckWinningRate();

int main()
{
	Init();
	CheckWinningRate();
	cout << ans;
}

void Init()
{
	cin >> x >> y;
	z = floor((double)y * 100 / x);
}

void CheckWinningRate()
{
	if (z >= 99)
	{
		ans = -1;
		return;
	}

	int low = 0;
	int high = MAX;
	int mid = (low + high) / 2;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (floor((double)(y + mid) * 100 / (x + mid)) > z)
			high = mid - 1;
		else
			low = mid + 1;
	}
	ans = low;
	return;
}
