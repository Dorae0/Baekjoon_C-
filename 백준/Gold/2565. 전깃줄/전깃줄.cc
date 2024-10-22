#include <iostream>
#define MAX 501

using namespace std;
int n, len, startPoint, endPoint;
int numbers[MAX];
int dp[MAX];
void Init();
void DP();

int main()
{
    Init();
    DP();
    cout << n - len;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> startPoint >> endPoint;
        numbers[startPoint] = endPoint;
    }       
    for(int i = 0; i < MAX; i++)
        dp[i] = 1;
}

void DP()
{
    for(int i = 2; i < MAX; i++)
    {
        if(numbers[i] == 0) continue;
        for(int j = 1; j < i; j++)
        {
            if(numbers[j] == 0) continue;
            if(numbers[i] > numbers[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        len = max(len, dp[i]);
    }
    len = max(len, dp[1]);
}