#include <iostream>
#define MAX 2001

using namespace std;
int n, m, s, e;
int numbers[MAX];
bool dp[MAX][MAX];

void init();
void makeDP();
void isPalindrome();

int main()
{
    init();
    makeDP();
    isPalindrome();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> numbers[i];
    cin >> m;
}

void makeDP()
{
    for(int c = 1; c <= n; c++)
        dp[c][c] = true;
    
    for(int c = 1; c < n; c++)
        if(numbers[c] == numbers[c + 1])
            dp[c][c + 1] = true;

    for(int c = 1; c <= n; c++)
    {
        int startPoint = c;
        int endPoint = c;
        while(--startPoint >= 1 && ++endPoint <= n)
            if(dp[startPoint + 1][endPoint - 1] && numbers[startPoint] == numbers[endPoint])
                dp[startPoint][endPoint] = true;
    }

    for(int c = 1; c < n; c++)
    {
        int startPoint = c;
        int endPoint = c + 1;
        while(--startPoint >= 1 && ++endPoint <= n)
            if(dp[startPoint + 1][endPoint - 1] && numbers[startPoint] == numbers[endPoint])
                dp[startPoint][endPoint] = true;
    }
}

void isPalindrome()
{
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e;
        if(dp[s][e])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}