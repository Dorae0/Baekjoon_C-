#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, temp, diffval = 0;
int start_iter = 0, end_iter = 0;
int ans = INT32_MAX;
vector<int> v;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	while (start_iter <= end_iter)
	{
		if (end_iter == n)
			break;
		else
		{
			diffval = v[end_iter] - v[start_iter];
			if (diffval < m)
			{
				end_iter++;
			}
			else
			{
				ans = min(ans, diffval);
				start_iter++;
			}
		}
	}

	cout << ans;

	return 0;
}