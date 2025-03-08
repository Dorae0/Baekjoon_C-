#include <iostream>
#include <string>
#define MAX 25

using namespace std;
int n, ans;
string s;
int stringData[MAX];

void Init();
void Fonts(int currentIdx, int currentData);

int main()
{
	Init();
	Fonts(0, 0);
	cout << ans;
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			stringData[i] |= (1 << (s[j] - 'a'));
	}
}

void Fonts(int currentIdx, int currentData)
{
	if (currentData == (1 << 26) - 1 && currentIdx == n)
		ans++;
	if (currentIdx < n)
	{
		Fonts(currentIdx + 1, currentData | stringData[currentIdx]);
		Fonts(currentIdx + 1, currentData);
	}
}