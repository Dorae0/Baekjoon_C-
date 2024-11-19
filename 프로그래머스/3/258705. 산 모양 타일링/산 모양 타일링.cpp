#include <string>
#include <vector>

using namespace std;

vector<int> dp;
int DP(int n, vector<int> tops);

int solution(int n, vector<int> tops) {
    int answer = 0;
    answer = DP(n, tops);
    return answer;
}

int DP(int n, vector<int> tops)
{
    for(int i = 0; i < 2 * n + 1; i++)
    {
        if(i == 0)
            dp.push_back(1);
        else if(i == 1)
        {
            if(!tops[0])
                dp.push_back(2);
            else
                dp.push_back(3);
        }
        else
        {
            if(i % 2)
            {
                if(tops[i / 2])
                    dp.push_back((dp[i - 1] * 2 + dp[i - 2]) % 10007);
                else
                    dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
            }
            else
                dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
        }
    }
    return dp[2 * n];
}