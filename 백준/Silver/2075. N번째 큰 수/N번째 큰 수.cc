#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

void push();
void print();

int main()
{
	cin >> n;
	push();
	print();
	return 0;
}

void push()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if(pq.size() < n)
				pq.push(temp);
			else if (pq.top() < temp)
			{
				pq.pop();
				pq.push(temp);
			}	
		}
}

void print()
{
	cout << pq.top();
}