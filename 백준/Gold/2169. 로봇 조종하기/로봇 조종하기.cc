#include <iostream>
#include <queue>
#define MAX 1000
#define INF ~0U >> 2

using namespace std;
int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];
int temp[MAX][2];
bool visited[MAX][MAX];
int dx[3] = {-1, 1, 0};
int dy[3] = {0, 0, 1};

void Init();
bool IsValid(int PosY, int PosX);
void DP();

int main()
{
    Init();
    DP();
    cout << dp[n - 1][m - 1];
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
}

bool IsValid(int PosY, int PosX)
{
    if(PosY >= 0 && PosX >= 0 && PosY < n && PosX < m)
        return true;
    return false;
}

void DP()
{
    int CurrentRow = 0;
    for(int i = 0; i < m; i++)
    {
        CurrentRow += map[0][i];
        dp[0][i] = CurrentRow;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            temp[j][0] = dp[i - 1][j] + map[i][j];
            temp[j][1] = dp[i - 1][j] + map[i][j];
        }
        for(int j = 0; j < m - 1; j++)
            temp[j + 1][0] = max(temp[j + 1][0], temp[j][0] + map[i][j + 1]);
        for(int j = m - 1; j > 0; j--)
            temp[j - 1][1] = max(temp[j - 1][1], temp[j][1] + map[i][j - 1]);
        for(int j = 0; j < m; j++)
            dp[i][j] = max(temp[j][0], temp[j][1]);
    }
}