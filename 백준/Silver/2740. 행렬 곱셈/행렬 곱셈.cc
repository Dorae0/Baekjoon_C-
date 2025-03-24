#include <iostream>
#define MAX 100

using namespace std;
int nA, mA, nB, mB;
int A[MAX][MAX], B[MAX][MAX], ans[MAX][MAX];

void Init();
void MatMul();

int main()
{
	Init();
	MatMul();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> nA >> mA;
	for (int i = 0; i < nA; i++)
		for (int j = 0; j < mA; j++)
			cin >> A[i][j];

	cin >> nB >> mB;
	for (int i = 0; i < nB; i++)
		for (int j = 0; j < mB; j++)
			cin >> B[i][j];
}

void MatMul()
{
	for(int i = 0; i < nA; i++)
		for (int j = 0; j < mB; j++)
		{
			int dx = 0, dy = 0;
			for (int k = 0; k < nB; k++)
			{
				ans[i][j] += A[i][dx] * B[dy][j];
				dx++; dy++;
			}
		}

	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mB; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}