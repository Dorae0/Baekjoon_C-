#include <iostream>
#include <vector>
#define DIVIDER 1'000'000'007

using namespace std;

int n;
long long x, k, ans;
vector<int> binaryK;

void Init();
void Present();
vector<int> GetBinary(long long num);
long long CalculatePower(int x);

int main()
{
	Init();
	Present();
	return 0;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void Present()
{
	for (int i = 0; i < n; i++)
	{
		cin >> x >> k;
		binaryK = GetBinary(k);
		ans += CalculatePower(x);
		ans %= DIVIDER;
	}
	cout << ans;
}

vector<int> GetBinary(long long num)
{
	vector<int> v;
	while (num)
	{
		v.push_back(num % 2);
		num /= 2;
	}
	return v;
}

long long CalculatePower(int x)
{
	long long currentNum = 1;
	long long ret = 0;
	for (int i = 0; i < binaryK.size(); i++)
	{
		if (binaryK[i])
		{
			ret += currentNum;
			ret %= DIVIDER;
		}
		currentNum *= x;
		currentNum %= DIVIDER;
	}
	return ret;
}