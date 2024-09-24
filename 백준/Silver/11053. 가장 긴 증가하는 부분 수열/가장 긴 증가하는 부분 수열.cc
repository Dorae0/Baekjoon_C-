#include <iostream>
#define MAX 1000

using namespace std;
int n, len;
int Values[MAX];
int dp[MAX];

void DP();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> Values[i];
    DP();
    cout << len;
}

void DP()
{
    for(int i = 0; i < n; i++)
        dp[i]++;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
            if(Values[i] > Values[j])
                dp[i] = max(dp[i], dp[j] + 1);
        len = max(len, dp[i]);
    }
    len = max(len, dp[0]);
}