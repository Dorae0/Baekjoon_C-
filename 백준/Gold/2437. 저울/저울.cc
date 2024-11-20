#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, temp;
vector<int> v;

void Init();
void Solve();

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
}

void Solve()
{
    int CurrentMax = 1;
    int CurrentIdx = 0;
    if(v[0] != 1)
    {
        cout << 1;
        return;
    }
    while(++CurrentIdx < n)
    {
        if(CurrentMax + 1 < v[CurrentIdx])
        {
            cout << CurrentMax + 1;
            return;
        }
        else
            CurrentMax += v[CurrentIdx];
        
    }
    cout << CurrentMax + 1;
}