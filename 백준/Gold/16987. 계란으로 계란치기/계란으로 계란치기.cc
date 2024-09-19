#include <iostream>
#define MAX 8

using namespace std;
int n, ans;
int eggData[MAX][2];
int HitEgg(int eggNum1, int eggNum2);
void RestoreEgg(int eggNum1, int eggNum2);
void eggBreak(int eggNum, int brokenEgg);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> eggData[i][0] >> eggData[i][1];
    eggBreak(0, 0);
    cout << ans;
}

int HitEgg(int eggNum1, int eggNum2)
{
    int ans = 0;
    eggData[eggNum1][0] -= eggData[eggNum2][1];
    eggData[eggNum2][0] -= eggData[eggNum1][1];
    if(eggData[eggNum1][0] <= 0) ans++;
    if(eggData[eggNum2][0] <= 0) ans++;
    return ans;
}

void RestoreEgg(int eggNum1, int eggNum2)
{
    eggData[eggNum1][0] += eggData[eggNum2][1];
    eggData[eggNum2][0] += eggData[eggNum1][1];
}

void eggBreak(int eggNum, int brokenEgg)
{
    ans = max(ans, brokenEgg);
    for(int i = 0; i < n; i++)
    {
        if(i == eggNum) continue;
        if(eggData[i][0] > 0)
        {
            int brokenEggs = HitEgg(eggNum, i);
            int NextEgg = -1;
            for(int j = eggNum + 1; j < n; j++)
            {
                if(eggData[j][0] > 0)
                {
                    NextEgg = j;
                    break;
                }
            }
            if(NextEgg > 0)
                eggBreak(NextEgg, brokenEgg + brokenEggs);
            else
                ans = max(ans, brokenEgg + brokenEggs);
            RestoreEgg(eggNum, i);
        }
    }
}