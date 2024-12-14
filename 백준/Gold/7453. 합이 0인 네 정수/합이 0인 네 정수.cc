#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int n, temp;
vector<int> nums[4];
vector<int> left_v, right_v;

void init();
void zeroSum();

int main()
{
    init();
    zeroSum();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
        {
            cin >> temp;
            nums[j].push_back(temp);
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            {
                left_v.push_back(nums[0][i] + nums[1][j]);
                right_v.push_back(nums[2][i] + nums[3][j]);
            }
    sort(right_v.begin(), right_v.end());
}

void zeroSum()
{
    long long ans = 0;
    for(int i = 0; i < left_v.size(); i++)
    {
        int targetNum = left_v[i] * (-1);
        int left = 0;
        int right = right_v.size();
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(right_v[mid] >= targetNum)
                right = mid;
            else
                left = mid + 1;
        }
        int mid_left = left;
        left = 0;
        right = right_v.size();
        mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(right_v[mid] > targetNum)
                right = mid;
            else
                left = mid + 1;
        }
        int mid_right = left;
        ans += (mid_right - mid_left);
    }
    cout << ans;
}