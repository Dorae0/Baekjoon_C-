#include <iostream>
#include <cstring>
#define MAX 16
#define INF ~0U >> 2

using namespace std;

int n, maxnum;
int map[MAX][MAX];
int dp[MAX][1 << MAX];

int dfs(int Node, int Path);

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    maxnum = (1 << n) - 1;
    cout << dfs(0, 1);
}

int dfs(int Node, int Path)
{
    if(Path == maxnum)
    {
        if(map[Node][0] == 0)
            return INF;
        return map[Node][0];
    }
    if(dp[Node][Path] != -1)
        return dp[Node][Path];
    else
    {
        dp[Node][Path] = INF;
        for(int i = 0; i < n; i++)
        {
            if(map[Node][i] == 0) continue;
            if((Path & (1 << i)) == (1 << i)) continue;
            dp[Node][Path] = min(dp[Node][Path], dfs(i, Path | (1 << i)) + map[Node][i]);
        }
    }
    return dp[Node][Path];
}
