#include <iostream>

using namespace std;
long long n;
long long ans;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
	cin >> n;
	cout << (n - 1) * (n - 1) << '\n';
	for (int i = 2; i <= n; i++)
		cout << 1 << ' ' << i << '\n';
}