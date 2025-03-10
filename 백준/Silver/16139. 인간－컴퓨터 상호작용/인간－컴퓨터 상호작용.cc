#include <iostream>
#include <string>
#define MAX 200000

using namespace std;

string s;
int q, l, r;
char a;

int charCount[MAX][26];

void Init();
void PrefixSum();
void Solve();

int main()
{
	Init();
	PrefixSum();
	Solve();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s >> q;
}

void PrefixSum()
{
	for (int i = 0; i < s.length(); i++)
	{
		if(i > 0)
			for (int j = 0; j < 26; j++)
				charCount[i][j] = charCount[i - 1][j];
		charCount[i][s[i] - 'a']++;
	}
}

void Solve()
{
	for (int i = 0; i < q; i++)
	{
		cin >> a >> l >> r;
		if (l == 0)
			cout << charCount[r][a - 'a'] << '\n';
		else
			cout << charCount[r][a - 'a'] - charCount[l - 1][a - 'a'] << '\n';
	}
}