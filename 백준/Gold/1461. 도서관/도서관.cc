#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, temp;
vector<int> books_upper;
vector<int> books_lower;

void Init();
int Solve();

int main()
{
    Init();
    cout << Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp > 0)
            books_upper.push_back(temp);
        else
            books_lower.push_back(temp);
    }
    sort(books_upper.begin(), books_upper.end());
    sort(books_lower.begin(), books_lower.end());
}

int Solve()
{
    int ans = 0;
    for(int i = books_upper.size() - 1; i >= 0; i -= m)
        ans += books_upper[i] * 2;
    for(int i = 0; i < books_lower.size(); i += m)
        ans -= books_lower[i] * 2;

    if(books_upper.empty())
        ans -= -books_lower[0];
    else if(books_lower.empty())
        ans -= books_upper[books_upper.size() - 1];
    else
        ans -= max(books_upper[books_upper.size() - 1], -books_lower[0]);
        
    return ans;
}