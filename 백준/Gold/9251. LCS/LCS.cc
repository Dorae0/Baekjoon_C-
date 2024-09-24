#include <iostream>
#include <string>
#define MAX 1000

using namespace std;
string s1, s2;
int dp[MAX][MAX];

void DP();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    DP();
    cout << dp[s1.length() - 1][s2.length() - 1];
}

void DP()
{
    int Len1 = s1.length();
    int Len2 = s2.length();
    for(int i = 0; i < Len1; i++)
        for(int j = 0; j < Len2; j++)
        {
            int Upper_Value = 0;
            int Left_Value = 0;
            int Diagonal_Value = 0;
            if(i > 0)
                Left_Value = dp[i - 1][j];
            if(j > 0)
                Upper_Value = dp[i][j - 1];
            if(i > 0 && j > 0)
                Diagonal_Value = dp[i - 1][j - 1];
            if(s1[i] != s2[j])
                dp[i][j] = max(Upper_Value, Left_Value);
            else
                dp[i][j] = Diagonal_Value + 1;
        }
}