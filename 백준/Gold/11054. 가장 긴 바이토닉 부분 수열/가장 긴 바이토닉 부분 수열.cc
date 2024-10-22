#include <iostream>
#define MAX 1001

using namespace std;
int numbers[MAX];
int dp_ASC[MAX];
int dp_DESC[MAX];

int n, temp, ans;
void Init();
void DP_ASC();
void DP_DESC();
void Solve();

int main()
{
    Init();
    DP_ASC();
    DP_DESC();
    Solve();
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    for(int i = 0; i < n; i++)
    {
        dp_ASC[i] = 1;
        dp_DESC[i] = 1;
    }
}

void DP_ASC()
{
    int len = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(numbers[i] > numbers[j])
                dp_ASC[i] = max(dp_ASC[i], dp_ASC[j] + 1);
        }
    }
}

void DP_DESC()
{
    int len = 0;
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(numbers[i] > numbers[j])
                dp_DESC[i] = max(dp_DESC[i], dp_DESC[j] + 1);
        }
    }
}

void Solve()
{
    for(int i = 0; i < n; i++)
    {
        if(ans < dp_ASC[i] + dp_DESC[i] - 1)
            ans = dp_ASC[i] + dp_DESC[i] - 1;
    }
}