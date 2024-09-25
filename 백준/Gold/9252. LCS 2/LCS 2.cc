#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000

using namespace std;
string s1, s2, ans;
int dp[MAX][MAX];

void DP();
void CheckString();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    DP();
    if (dp[s1.length() - 1][s2.length() - 1] == 0)
        cout << dp[s1.length() - 1][s2.length() - 1];
    else
    {
        CheckString();
        reverse(ans.begin(), ans.end());
        cout << dp[s1.length() - 1][s2.length() - 1] << '\n' << ans;
    }
}

void DP()
{
    int Len1 = s1.length();
    int Len2 = s2.length();
    for (int i = 0; i < Len1; i++)
        for (int j = 0; j < Len2; j++)
        {
            int Upper_Value = 0;
            int Left_Value = 0;
            int Diagonal_Value = 0;
            if (i > 0)
                Upper_Value = dp[i - 1][j];
            if (j > 0)
                Left_Value = dp[i][j - 1];
            if (i > 0 && j > 0)
                Diagonal_Value = dp[i - 1][j - 1];
            if (s1[i] != s2[j])
                dp[i][j] = max(Upper_Value, Left_Value);
            else
                dp[i][j] = Diagonal_Value + 1;
        }
}

void CheckString()
{
    int NodeY = s1.length() - 1;
    int NodeX = s2.length() - 1;
    while(NodeX >= 0 && NodeY >= 0)
    {
        int Left_Value = 0;
        int Upper_Value = 0;
        int Diagonal_Value = 0;
        int Current_Value = dp[NodeY][NodeX];
        if (NodeX > 0)
            Left_Value = dp[NodeY][NodeX - 1];
        if (NodeY > 0)
            Upper_Value = dp[NodeY - 1][NodeX];
        if (NodeX > 0 && NodeY > 0)
            Diagonal_Value = dp[NodeY - 1][NodeX - 1];

        if(Current_Value == Left_Value)
            NodeX--;
        else if(Current_Value == Upper_Value)
            NodeY--;
        else          
        {
            ans.push_back(s1[NodeY]);
            NodeX--; NodeY--;
        }
    }
}