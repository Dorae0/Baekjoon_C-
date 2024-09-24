#include <iostream>
#define CONTENTS_MAX 101
#define WEIGHT_MAX 100001

using namespace std;
int n, k, w, v, ans;
pair<int, int> contents[CONTENTS_MAX];
int dp[CONTENTS_MAX][WEIGHT_MAX];

void Input();
void DP();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    Input();
    DP();
    cout << ans;
}

void Input()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> w >> v;
        contents[i] = {w, v};
    }
}

void DP()
{
    for(int i = 1; i <= k; i++) // weight
        for(int j = 1; j <= n; j++) // contents
        {
            if(contents[j].first > i)
                dp[j][i] = dp[j-1][i];
            else
                dp[j][i] = max(dp[j-1][i], dp[j-1][i - contents[j].first] + contents[j].second);
        }
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i][k]);
}