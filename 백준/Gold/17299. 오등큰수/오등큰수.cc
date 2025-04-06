#include <iostream>
#include <stack>

#define MAX 1'000'000

using namespace std;

int n;
int numbers[MAX];
int ans[MAX];
int Fn[MAX + 1];
stack<int> stck;

void Init();
void NGF();

int main()
{
	Init();
	NGF();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		Fn[numbers[i]]++;
	}
}

void NGF()
{
	for (int i = n - 1; i >= 0;)
	{
		if (stck.empty())
		{
			stck.push(numbers[i]);
			ans[i] = -1;
			i--;
		}
		else
		{
			if (Fn[stck.top()] > Fn[numbers[i]])
			{
				ans[i] = stck.top();
				stck.push(numbers[i]);
				i--;
			}
			else
				stck.pop();
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}