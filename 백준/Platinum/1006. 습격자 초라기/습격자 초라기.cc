#include <iostream>
#include <algorithm>
#define MAX 10'001
#define INF ~0U >> 2

using namespace std;
int t, n, w, ans = INF, dp[MAX][3], map[2][MAX];
bool upper, lower;

void Init();
void Raider();
int DP(bool upper, bool lower);

int main()
{
    Init();
    Raider();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
}

void Raider()
{
    for (int i = 0; i < t; i++)
    {
        cin >> n >> w;
        upper = false; lower = false;
        for (int j = 0; j < 2; j++)
            for (int k = 1; k <= n; k++)
                cin >> map[j][k];
        if (n >= 2 && map[0][1] + map[0][n] <= w)
            upper = true;
        if (n >= 2 && map[1][1] + map[1][n] <= w)
            lower = true;
        ans = INF;
        if (upper)
        {
            ans = min(ans, DP(true, false));
            if (lower)
                ans = min(ans, DP(true, true));
        }
        if (lower)
            ans = min(ans, DP(false, true));
        ans = min(ans, DP(false, false));

        cout << ans << '\n';
    }
}

int DP(bool upper, bool lower)
{
    int upperBegin = map[0][1];
    int upperEnd = map[0][n];
    int lowerBegin = map[1][1];
    int lowerEnd = map[1][n];

    if (upper)
    {
        map[0][1] = INF;
        map[0][n] = INF;
    }

    if (lower)
    {
        map[1][1] = INF;
        map[1][n] = INF;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = INF; dp[i][1] = INF; dp[i][2] = INF;

        // dp[n][1]

        dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        if (map[1][i - 1] + map[1][i] <= w)
            dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);

        // dp[n][2]

        dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        if (map[0][i - 1] + map[0][i] <= w)
            dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);

        // dp[n][0]

        dp[i][0] = min(dp[i][0], dp[i][1] + 1);
        dp[i][0] = min(dp[i][0], dp[i][2] + 1);
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
        if (map[0][i] + map[1][i] <= w)
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);

        if (i >= 2)
        {
            if (map[0][i - 1] + map[0][i] <= w && map[1][i - 1] + map[1][i] <= w)
                dp[i][0] = min(dp[i][0], dp[i - 2][0] + 2);
            else if (map[0][i - 1] + map[0][i] <= w || map[1][i - 1] + map[1][i] <= w)
                dp[i][0] = min(dp[i][0], dp[i - 2][0] + 3);
        }
    }

    map[0][1] = upperBegin;
    map[0][n] = upperEnd;
    map[1][1] = lowerBegin;
    map[1][n] = lowerEnd;

    if (upper)
        dp[n][0]--;
    if (lower)
        dp[n][0]--;

    return dp[n][0];
}