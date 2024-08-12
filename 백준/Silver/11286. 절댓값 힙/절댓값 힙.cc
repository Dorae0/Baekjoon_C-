#include <iostream>
#include <queue>
using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> positive_pq, negative_pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x != 0)
		{
			if (x > 0)
				positive_pq.push(x);
			else
				negative_pq.push(x * (-1));
		}
		else
		{
			if (positive_pq.size() == 0)
			{
				if(negative_pq.size() == 0)
					cout << 0 << endl;
				else
				{
					cout << negative_pq.top() * (-1) << endl;
					negative_pq.pop();
				}
			}
			else if (negative_pq.size() == 0)
			{
				cout << positive_pq.top() << endl;
				positive_pq.pop();
			}			
			else
			{
				if (positive_pq.top() >= negative_pq.top())
				{
					cout << negative_pq.top() * (-1) << endl;
					negative_pq.pop();
				}
				else
				{
					cout << positive_pq.top() << endl;
					positive_pq.pop();
				}
			}
		}
	}
	return 0;
}