#include <iostream>
#include <string>
#define MAX 100

using namespace std;
string s1, s2, s3;

int dp[MAX][MAX][MAX];

void init();
int DP();

int main()
{
    init();
    cout << DP();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3;
}

int DP()
{
    for(int h = 0; h < s3.size(); h++)
    {
        for(int j = 0; j < s2.size(); j++)
            for(int i = 0; i < s1.size(); i++)
            {
                int leftDP = 0;
                int upperDP = 0;
                int lowerDP = 0;
                int diagonalDP = 0;
                if(i)
                    leftDP = dp[h][j][i - 1];
                if(j)
                    upperDP = dp[h][j - 1][i];
                if(h)
                    lowerDP = dp[h - 1][j][i];
                if(i && j && h)
                    diagonalDP = dp[h - 1][j - 1][i - 1];

                if(s1[i] == s2[j] && s2[j] == s3[h])
                    dp[h][j][i] = diagonalDP + 1;
                else
                    dp[h][j][i] = max(max(leftDP, upperDP), lowerDP);
            }
    }
    return dp[s3.size() - 1][s2.size() - 1][s1.size() - 1];
}