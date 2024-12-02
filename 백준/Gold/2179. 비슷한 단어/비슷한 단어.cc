#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int n;
string s;
map<string, vector<int>> mp;
vector<string> v;

void Init();
void mapPush();
void Solve();

int main()
{
	Init();
	mapPush();
	Solve();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void mapPush()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
		string CurrentString = "";
		for (int j = 0; j < s.length(); j++)
		{
			CurrentString.push_back(s[j]);
			mp[CurrentString].push_back(i);
		}
	}
}

void Solve()
{
	int maxlen = 0;
	string maxKey = "";
	int maxOrder = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->second.size() <= 1) continue;
		int CurrentLen = it->first.length();
		if (maxlen < CurrentLen)
		{
			maxlen = CurrentLen;
			maxKey = it->first;
			maxOrder = it->second[0];
		}
		else if (maxlen == CurrentLen)
		{
			if (maxOrder > it->second[0])
			{
				maxKey = it->first;
				maxOrder = it->second[0];
			}
		}
	}
	cout << v[mp[maxKey][0]] << '\n' << v[mp[maxKey][1]];
}