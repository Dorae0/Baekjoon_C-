#include <iostream>
#include <vector>
#define MAX 501

using namespace std;
using pll = pair<long long, long long>;

long long n, x, y;
vector<pll> v;

long long dp[MAX][MAX];

void init();
void matMul();

int main()
{
    init();
    matMul();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    v.push_back({0, 0});
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
}

void matMul()
{
    if(n == 1)
    {
        cout << v[1].first * v[1].second;
        return;
    }
    for(int i = 2; i <= n; i++)
        for(int j = i - 1; j > 0; j--)
        {
            long long minVal = ~0U;
            for(int k = j; k < i; k++)
                minVal = min(minVal, dp[j][k] + dp[k + 1][i] + (v[j].first * v[k + 1].first * v[i].second));
            dp[j][i] = minVal;
        }
    cout << dp[1][n];
}