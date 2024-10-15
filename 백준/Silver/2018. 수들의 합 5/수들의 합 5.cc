#include <iostream>

using namespace std;
int n;
int CountNum();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cout << CountNum();
}

int CountNum()
{
    int left = 1;
    int right = 1;
    int CurrentSum = 1;
    int ans = 0;
    while(right <= n)
    {
        if(CurrentSum <= n)
        {
            if(CurrentSum == n) ans++;
            CurrentSum += ++right;
        }
        else if(CurrentSum > n)
            CurrentSum -= left++;
    }
    return ans;
}