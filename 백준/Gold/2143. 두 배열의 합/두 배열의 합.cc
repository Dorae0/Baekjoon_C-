#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;
int t, n, m, A[MAX], B[MAX];
long long ans;
vector<int> aPrefix, bPrefix;

void Init();
void MakePrefix();

int main()
{
	Init();
	MakePrefix();
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> B[i];
		B[i] += B[i - 1];
	}
}

void MakePrefix()
{
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			aPrefix.push_back(A[j] - A[i]);

	for (int i = 0; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			bPrefix.push_back(B[j] - B[i]);

	sort(aPrefix.begin(), aPrefix.end());
	sort(bPrefix.begin(), bPrefix.end());

	if (n < m)
		for (int i = 0; i < aPrefix.size(); i++)
			ans += upper_bound(bPrefix.begin(), bPrefix.end(), t - aPrefix[i]) - lower_bound(bPrefix.begin(), bPrefix.end(), t - aPrefix[i]);
	else
		for (int i = 0; i < bPrefix.size(); i++)
			ans += upper_bound(aPrefix.begin(), aPrefix.end(), t - bPrefix[i]) - lower_bound(aPrefix.begin(), aPrefix.end(), t - bPrefix[i]);

	cout << ans;
}