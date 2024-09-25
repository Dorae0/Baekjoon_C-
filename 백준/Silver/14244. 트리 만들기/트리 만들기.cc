#include <iostream>

using namespace std;
int n, m;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n - m; i++)
		cout << i << ' ' << i + 1 << '\n';
	for (int i = n - m + 1; i < n; i++)
		cout << n - m << ' ' << i << '\n';
}