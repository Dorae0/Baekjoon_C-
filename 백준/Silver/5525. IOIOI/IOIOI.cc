#include <iostream>
#include <string>

using namespace std;
int n, m, temp, val = 0;
string s;
int flag;

int main()
{
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < m; i++)
	{
		if (i == m - 1)
		{
			temp = flag / 2 - n + 1;
			if (temp >= 0) val += temp;
			flag = 0;
		}
		else if (flag == 0)
		{
			if (s[i] == 'I' && s[i + 1] == 'O')
				flag++;
		}
		else
		{
			if (s[i] != s[i + 1])
				flag++;
			else
			{
				temp = flag / 2 - n + 1;
				if (temp >= 0) val += temp;
				flag = 0;
			}
		}
	}
	cout << val;
	return 0;
}