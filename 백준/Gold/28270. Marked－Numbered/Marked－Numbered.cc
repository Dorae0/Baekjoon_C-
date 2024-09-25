#include <iostream>
#define MAX 1000001

using namespace std;
int n;
int marked[MAX];
int numbered[MAX];
int indexCount[MAX];

void Flush(int x);
void markedToNumbered();

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	marked[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> marked[i];
		if (marked[i] - marked[i - 1] > 1)
		{
			cout << -1;
			return 0;
		}
	}
	markedToNumbered();
	return 0;
}

void Flush(int x)
{
	for (int i = x; i <= n; i++)
		indexCount[i] = 0;
}

void markedToNumbered()
{
	for (int i = 1; i <= n; i++)
	{
		int CurrentMark = marked[i];
		int PreviousMark = marked[i - 1];
		if (CurrentMark < PreviousMark)
			Flush(PreviousMark);
		numbered[i] = ++indexCount[CurrentMark];
	}
	for (int i = 1; i <= n; i++)
		cout << numbered[i] << ' ';
}