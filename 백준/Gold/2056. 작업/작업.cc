#include <iostream>
#define MAX 10000

using namespace std;
int n, t, x, temp;
int dp[MAX];

void Init();
void Solve();

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        cin >> x;
        int maxVal = 0;
        for(int j = 0; j < x; j++)
        {
            cin >> temp;
            maxVal = max(maxVal, dp[temp]);
        }
        dp[i] = maxVal + t;
    }
}

void Solve()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}