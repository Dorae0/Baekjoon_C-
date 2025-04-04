#include <iostream>
#include <queue>

using namespace std;
int t, m, temp;
priority_queue<int> pq;
queue<int> q;

void Init();
void GetMiddle();

int main()
{
	Init();
	for (int i = 0; i < t; i++)
		GetMiddle();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
}

void GetMiddle()
{
	while (!pq.empty()) pq.pop();
	cin >> m;
	cout << m / 2 + 1 << '\n';
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		pq.push(temp);
		if (i % 2 == 0)
		{
			int pqSize = pq.size();
			for (int j = 0; j < pqSize / 2; j++)
			{
				q.push(pq.top());
				pq.pop();
			}
			cout << pq.top() << ' ';
			while (!q.empty())
			{
				pq.push(q.front());
				q.pop();
			}
		}
	}
	cout << '\n';
}