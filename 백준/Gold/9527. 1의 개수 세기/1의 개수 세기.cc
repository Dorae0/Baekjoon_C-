#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long a, b, aCount, bCount;
vector<long long> binaryA, binaryB;

void Init();
void MakeBinary();
long long GetValue(char targetNum, int Idx);
void Calculate();

int main()
{
	Init();
	MakeBinary();
	Calculate();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	a--;
}

void MakeBinary()
{
	while (a > 0)
	{
		binaryA.push_back(a % 2);
		a /= 2;
	}
	while (b > 0)
	{
		binaryB.push_back(b % 2);
		b /= 2;
	}
}

long long GetValue(char targetNum, int Idx)
{
	long long ans = 0;
	if (targetNum == 'A')
	{
		long long power = 1;
		for (int i = 0; i < Idx; i++)
		{
			ans += binaryA[i] * power;
			power *= 2;
		}
	}
	else if (targetNum == 'B')
	{
		long long power = 1;
		for (int i = 0; i < Idx; i++)
		{
			ans += binaryB[i] * power;
			power *= 2;
		}
	}
	return ans + 1;
}

void Calculate()
{
	for (int i = 0; i < binaryA.size(); i++)
		if (binaryA[i] == 1)
		{
			if (i != 0)
			{
				aCount += (1LL << (i - 1)) * i;
				aCount += GetValue('A', i);
			}
			else
				aCount += binaryA[i];
		}

	for (int i = 0; i < binaryB.size(); i++)
		if (binaryB[i] == 1)
		{
			if (i != 0)
			{
				bCount += (1LL << (i - 1)) * i;
				bCount += GetValue('B', i);
			}
			else
				bCount += binaryB[i];
		}

	cout << bCount - aCount;
}