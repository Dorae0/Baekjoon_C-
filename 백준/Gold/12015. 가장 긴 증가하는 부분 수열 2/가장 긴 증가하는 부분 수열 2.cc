#include <iostream>
#include <vector>
#define MAX 1'000'001

using namespace std;

int n, temp, ans;
vector<int> v;

void init();
void LIS();

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
    v.push_back(-MAX);
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        if(v.back() < temp)
        {
            v.push_back(temp);
            ans++;
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), temp);
            *it = temp;
        } 
    }
    cout << ans;
}