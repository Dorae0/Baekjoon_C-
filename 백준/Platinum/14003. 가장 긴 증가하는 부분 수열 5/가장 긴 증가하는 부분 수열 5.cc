#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1'000'001
#define INF -1'000'000'001

using namespace std;

int n, temp, ans;
bool isChecked;
vector<int> v;
vector<int> numbers;
vector<int> dp;
vector<int> answer;

void init();
void LIS();
void backtracking(int currentNum, int currentIdx);

int main()
{
    init();
    LIS();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void LIS()
{
    v.push_back(INF);
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
        if(v.back() < temp)
        {
            v.push_back(temp);
            ans++;
            dp.push_back(ans);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), temp);
            *it = temp;
            dp.push_back(it - v.begin());
        } 
    }
    cout << ans << '\n';
    backtracking(ans, n - 1);
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
}

void backtracking(int currentNum, int currentIdx)
{
    if(currentNum == 0)
    {
        isChecked = true;
        reverse(answer.begin(), answer.end());
        return;
    }
    for(int i = currentIdx; i >= 0; i--)
    {
        if(isChecked)
            return;
        if(dp[i] == currentNum)
        {
            answer.push_back(numbers[i]);
            backtracking(currentNum - 1, i);
        }
    }
}