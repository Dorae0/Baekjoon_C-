#include <iostream>
#define MAX 100000

enum minmax {
    MINIMUM,
    MAXIMUM,
};

using namespace std;
int n;
int map[MAX][3];
int dp[2][3][2];

void Init();
void DP();

int main()
{
    Init();
    DP();
    cout << max(dp[0][0][MAXIMUM], max(dp[0][1][MAXIMUM], dp[0][2][MAXIMUM])) << ' ' << min(dp[0][0][MINIMUM], min(dp[0][1][MINIMUM], dp[0][2][MINIMUM]));
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> map[i][0] >> map[i][1] >> map[i][2];
}

void DP()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            dp[0][i][j] = map[0][i];
    
    for(int i = 1; i < n; i++)
    {
        dp[1][0][MINIMUM] = map[i][0] + min(dp[0][0][MINIMUM], dp[0][1][MINIMUM]);
        dp[1][0][MAXIMUM] = map[i][0] + max(dp[0][0][MAXIMUM], dp[0][1][MAXIMUM]);
        dp[1][1][MINIMUM] = map[i][1] + min(dp[0][0][MINIMUM], min(dp[0][1][MINIMUM], dp[0][2][MINIMUM]));
        dp[1][1][MAXIMUM] = map[i][1] + max(dp[0][0][MAXIMUM], max(dp[0][1][MAXIMUM], dp[0][2][MAXIMUM]));
        dp[1][2][MINIMUM] = map[i][2] + min(dp[0][1][MINIMUM], dp[0][2][MINIMUM]);
        dp[1][2][MAXIMUM] = map[i][2] + max(dp[0][1][MAXIMUM], dp[0][2][MAXIMUM]);

        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2; k++)
                dp[0][j][k] = dp[1][j][k];
    }
}