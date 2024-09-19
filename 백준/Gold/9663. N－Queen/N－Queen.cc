#include <iostream>
#define MAX 14
using namespace std;
int Queens[MAX];
int n, ans;

bool IsLinear(int a)
{
	for (int i = 0; i < a; i++)
		if (Queens[i] == Queens[a] || abs(Queens[a] - Queens[i]) == a - i)
			return true;
	return false;
}

void NQueen(int x)
{
	if (x == n)
		ans++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			Queens[x] = i;
			if (!IsLinear(x)) NQueen(x + 1);
		}
	}
}

int main()
{
	cin >> n;
	NQueen(0);
	cout << ans;
	return 0;
}