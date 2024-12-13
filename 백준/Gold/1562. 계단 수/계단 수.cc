#include <iostream>
#define MAX 101
#define DIVIDER 1'000'000'000

using namespace std;
int n;
int stairsNum[MAX][10][1 << 10];

void init();
void dp();

int main()
{
    init();
    dp();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void dp()
{
    for(int i = 1; i < 10; i++)
        stairsNum[1][i][1 << i]++;
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < (1 << 10); k++)
            {
                if(j == 0)
                {
                    stairsNum[i][j][k | (1 << 0)] += stairsNum[i - 1][1][k];
                    stairsNum[i][j][k | (1 << 0)] %= DIVIDER;
                }
                else if(j == 9)
                {
                    stairsNum[i][j][k | (1 << 9)] += stairsNum[i - 1][8][k];
                    stairsNum[i][j][k | (1 << 9)] %= DIVIDER;
                }
                else
                {
                    stairsNum[i][j][k | (1 << j)] += stairsNum[i - 1][j + 1][k];
                    stairsNum[i][j][k | (1 << j)] += stairsNum[i - 1][j - 1][k];
                    stairsNum[i][j][k | (1 << j)] %= DIVIDER;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < 10; i++)
    {
        ans += stairsNum[n][i][1023];
        ans %= DIVIDER;
    }
    cout << ans;
}