#include <iostream>
#define MAX 100000
#define LOWER 0
#define UPPER 1

using namespace std;
int t, n;
int arr[MAX][2];
int dp[MAX][2];
void Solve();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> arr[j][UPPER];
        for(int j = 0; j < n; j++)   
            cin >> arr[j][LOWER];
        Solve();
    }
}

void Solve()
{
    dp[0][UPPER] = arr[0][UPPER];
    dp[0][LOWER] = arr[0][LOWER];

    dp[1][UPPER] = arr[1][UPPER] + arr[0][LOWER];
    dp[1][LOWER] = arr[1][LOWER] + arr[0][UPPER];

    for(int i = 2; i < n; i++)
    {
        dp[i][UPPER] = max(dp[i - 1][LOWER], dp[i - 2][LOWER])+ arr[i][UPPER];
        dp[i][LOWER] = max(dp[i - 1][UPPER], dp[i - 2][UPPER])+ arr[i][LOWER];
    }
    cout << max(dp[n - 1][LOWER], dp[n - 1][UPPER]) << '\n';
}