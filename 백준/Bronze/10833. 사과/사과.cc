#include <iostream>

using namespace std;
int n, student, apple, ans;

void Init();
void Apple();

int main()
{
	Init();
	Apple();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
}

void Apple()
{
	for (int i = 0; i < n; i++)
	{
		cin >> student >> apple;
		ans += apple % student;
	}
	cout << ans;
}