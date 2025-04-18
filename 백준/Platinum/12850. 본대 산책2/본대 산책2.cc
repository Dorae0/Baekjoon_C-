#include <iostream>
#include <vector>
#define DIVIDER 1'000'000'007

using namespace std;

int d;
vector<vector<long long>> map =
{
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0},
};
vector<vector<long long>> ans = 
{
	{1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 1},
};

void Init();
vector<vector<long long>> MatMul(vector<vector<long long>> A, vector<vector<long long>> B);
void Walk();

int main()
{
	Init();
	Walk();
	cout << ans[0][0] % DIVIDER;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> d;
}

vector<vector<long long>> MatMul(vector<vector<long long>> A, vector<vector<long long>> B)
{
	vector<vector<long long>> ans = 
	{
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
	};
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
			{
				ans[i][j] += A[i][k] * B[k][j];
				ans[i][j] %= DIVIDER;
			}

	return ans;
}

void Walk()
{
	while (d)
	{
		if (d % 2)
			ans = MatMul(ans, map);
		map = MatMul(map, map);
		d /= 2;
	}
}