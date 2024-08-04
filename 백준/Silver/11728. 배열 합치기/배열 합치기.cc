#include <iostream>
#include <vector>

using namespace std;
int n, m, temp, ai = 0, bi = 0;
vector <int> a, b, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }

    while(1)
    {
        if(a[ai] <= b[bi])
        {
            ans.push_back(a.at(ai));
            ai++;
        }
        else
        {
            ans.push_back(b.at(bi));
            bi++;
        }
        if(ai == a.size())
        {
            while(bi != b.size())
                ans.push_back(b.at(bi++));
            break;
        }
        else if(bi == b.size())
        {
            while(ai != a.size())
                ans.push_back(a.at(ai++));
            break;
        }
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans.at(i) << ' ';

    return 0;
}