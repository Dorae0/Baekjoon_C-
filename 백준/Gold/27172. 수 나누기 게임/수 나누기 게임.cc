#include <iostream>
#include <vector>
#define MAX 1'000'001

using namespace std;
int n, temp, number[MAX];
vector<int> num;

void Init();
void CheckDivisor(int x);
void CheckMultiple(int x);
void MakeScore();

int main()
{
	Init();
	MakeScore();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void CheckDivisor(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
		{
			number[i]++;
			if(x / i != i)
				number[x / i]++;
		}
	if (x != 1)
		number[1]++;
}

void CheckMultiple(int x)
{
	for (int i = x * 2; i < MAX; i += x)
		number[i]--;
}

void MakeScore()
{
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		num.push_back(temp);
		CheckDivisor(temp);
		CheckMultiple(temp);
	}

	for (int i = 0; i < num.size(); i++)
		cout << number[num[i]] << ' ';
}