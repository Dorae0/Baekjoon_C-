#include <iostream>
#define MAX 17

using namespace std;

enum directions{
    DIRECTION_HORIZONTAL,
    DIRECTION_VERTICAL,
    DIRECTION_DIAGONAL,
    DIRECTION_MAX
};

int n;
int map[MAX][MAX];
int dp[MAX][MAX][DIRECTION_MAX];

void Init();
void DP();

int main()
{
    Init();
    DP();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
    dp[1][2][DIRECTION_HORIZONTAL] = 1;
}

void DP()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j <= 2) continue;
            if(map[i][j] == 0)
            {
                dp[i][j][DIRECTION_HORIZONTAL] = dp[i][j - 1][DIRECTION_HORIZONTAL] + dp[i][j - 1][DIRECTION_DIAGONAL];
                dp[i][j][DIRECTION_VERTICAL] = dp[i - 1][j][DIRECTION_VERTICAL] + dp[i - 1][j][DIRECTION_DIAGONAL];
                if(map[i - 1][j] == 0 && map[i][j - 1] == 0)
                    dp[i][j][DIRECTION_DIAGONAL] = dp[i - 1][j - 1][DIRECTION_HORIZONTAL] + dp[i - 1][j - 1][DIRECTION_DIAGONAL] + dp[i - 1][j - 1][DIRECTION_VERTICAL];
            }
    }
    cout << dp[n][n][DIRECTION_HORIZONTAL] + dp[n][n][DIRECTION_DIAGONAL] + dp[n][n][DIRECTION_VERTICAL];
}