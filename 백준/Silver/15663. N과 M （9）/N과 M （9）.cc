#include <iostream>
#include <vector>
#include <map>
#define MAX 10001

using namespace std;
int m, n, temp;
map<int, int> mp;
vector<int> ans;
int visited[MAX];

void Init();
void Print();
void Backtracking(int count);

int main()
{
    Init();
    Backtracking(0);
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        mp[temp]++;
    }
}

void Backtracking(int count)
{
    if(count == m)
    {
        Print();
        return;
    }
    for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        int CurrentNum = iter->first;
        int CurrentVal = iter->second;
        if(visited[CurrentNum] < CurrentVal)
        {
            visited[CurrentNum]++;
            ans.push_back(CurrentNum);
            Backtracking(count + 1);
            ans.pop_back();
            visited[CurrentNum]--;
        }
    }
}

void Print()
{
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}