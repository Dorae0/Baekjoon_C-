#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, command, student, menu;
queue<pii> q;
vector<int> type[3];

void init();
void cafeteria();

int main()
{
	init();
	cafeteria();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void cafeteria()
{
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == 1)
		{
			cin >> student >> menu;
			q.push({ student, menu });
		}
		else if (command == 2)
		{
			cin >> menu;
			if (q.front().second == menu)
				type[0].push_back(q.front().first);
			else
				type[1].push_back(q.front().first);
			q.pop();
		}
	}
	while (!q.empty())
	{
		type[2].push_back(q.front().first);
		q.pop();
	}
	for (int i = 0; i < 3; i++)
	{
		if (type[i].empty()) cout << "None";
		else
		{
			sort(type[i].begin(), type[i].end());
			for (int j = 0; j < type[i].size(); j++)
				cout << type[i][j] << ' ';
		}
		cout << '\n';
	}
}