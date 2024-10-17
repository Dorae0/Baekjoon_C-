#include <iostream>
#define MAX 1024

using namespace std;
int n, m, x, Val;
int xFirst, xSecond, yFirst, ySecond;
int map[1025][1025];

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
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        Val = 0;
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            Val += x;
            map[i][j] = Val;
        }
    }
}

void Solve()
{
    for(int i = 0; i < m; i++)
    { 
        int ans = 0;
        cin >> xFirst >> yFirst >> xSecond >> ySecond;
        for(int j = xFirst; j <= xSecond; j++)
            ans += map[j][ySecond] - map[j][yFirst - 1];
        cout << ans << '\n';
    }
}