#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t;
string s;

int IsPalindrome(string s, int left_iter, int right_iter, int current_val);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		cout << IsPalindrome(s, 0, s.length() - 1, 0) << endl;
	}
	return 0;
}

int IsPalindrome(string s, int left_iter, int right_iter, int current_val)
{
	while (left_iter < right_iter)
	{
		if (s[left_iter] != s[right_iter])
		{
			if (current_val == 1)
				return 2;
			else
			{
				if (!IsPalindrome(s, left_iter + 1, right_iter, 1) || !IsPalindrome(s, left_iter, right_iter - 1, 1))
					return 1;
				else
					return 2;
			}
			}
		left_iter++;
		right_iter--;
	}
	return 0;
}