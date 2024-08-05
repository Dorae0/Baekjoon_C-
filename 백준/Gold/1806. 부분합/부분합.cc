#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, s, temp, tempval = 0, start_iter = 0, end_iter = 0, minval = INT32_MAX;
vector <int> ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        ans.push_back(temp);
    }
   while(start_iter <= end_iter)
    {
        if(tempval >= s)
        {
            minval = min(minval, end_iter - start_iter);
            tempval -= ans[start_iter++];
        }
        else if (end_iter == n) break;
        else tempval += ans[end_iter++];
    }

    if(minval == INT32_MAX)
        cout << 0;
    else
        cout << minval;

    return 0;
}