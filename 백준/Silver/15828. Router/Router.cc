#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, temp;

int main()
{
	cin >> n;
	while (1)
	{
		cin >> temp;
		if (temp == 0)
			q.pop();
		else if (temp == -1)
			break;
		else
		{
			if (q.size() <= n)
				q.push(temp);
		}
	}

	if (q.empty())
		cout << "empty";
	else
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
		}
	}

	return 0;
}