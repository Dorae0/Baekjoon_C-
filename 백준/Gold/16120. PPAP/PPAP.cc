#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s;
stack<char> stck;

void init();
bool PPAP();
int main()
{
	init();
	if (PPAP()) cout << "PPAP";
	else cout << "NP";
	return 0;
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
}

bool PPAP()
{
	for (int i = 0; i < s.length(); i++)
	{
		stck.push(s[i]);
		if (stck.size() >= 4 && s[i] == 'P')
		{
			string checkStr = "";
			for (int j = 0; j < 4; j++)
			{
				checkStr.push_back(stck.top());
				stck.pop();
			}
			if (checkStr == "PAPP")
				stck.push('P');
			else
				for (int j = 3; j >= 0; j--)
					stck.push(checkStr[j]);
		}
	}
	if (stck.size() == 1 && stck.top() == 'P')
		return true;
	else
		return false;
}