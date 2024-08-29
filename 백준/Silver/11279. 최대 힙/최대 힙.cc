#include <iostream>
#include <queue>

using namespace std;

int n, temp;
priority_queue<int> pq;

void pop();

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		switch (temp)
		{
		case 0:
			pop();
		default:
			pq.push(temp);
		}
	}
}

void pop()
{
	if (pq.empty())
		cout << '0' << '\n';
	else
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
}