#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, temp;
vector<int> num;
vector<int> ans;

void Init();
void Backtracking(int index, int Count);
void Print();

int main()
{
    Init();
    Backtracking(0, 0);
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        bool IsDuplicated = false;
        for(int j = 0; j < num.size(); j++)
            if(num[j] == temp) IsDuplicated = true;
        if(!IsDuplicated)
            num.push_back(temp);
    }
    sort(num.begin(), num.end());
}

void Backtracking(int index, int Count)
{
    if(Count == m)
    {
        Print();
        return;
    }
    for(int i = index; i < num.size(); i++)
    {
        int NextNum = num[i];
        ans.push_back(NextNum);
        Backtracking(i, Count + 1);
        ans.pop_back();
    }
}

void Print()
{
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}