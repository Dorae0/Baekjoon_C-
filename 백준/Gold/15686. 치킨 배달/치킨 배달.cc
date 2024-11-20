#include <iostream>
#include <vector>

using namespace std;
int n, m, temp;
int ans = ~0U >> 2;
bool visited[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

void Init();
void Backtracking(int CurrentIdx, int Count);
int CalculateDistance();

int main()
{
    Init();
    Backtracking(0, 0);
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            if(temp == 1)
                house.push_back({j, i});
            else if(temp == 2)
                chicken.push_back({j, i});
        }
}

void Backtracking(int CurrentIdx, int Count)
{
    if(Count == m)
    {
        ans = min(ans, CalculateDistance());
        return;
    }
    for(int i = CurrentIdx; i < chicken.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            Backtracking(i + 1, Count + 1);
            visited[i] = false;
        }
    }
}

int CalculateDistance()
{
    int ans = 0;
    for(int i = 0; i < house.size(); i++)
    {
        int CurrentDistance = ~0U >> 2;
        for(int j = 0; j < chicken.size(); j++)
        {
            if(visited[j])
                CurrentDistance = min(CurrentDistance, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
        }
        ans += CurrentDistance;
    }
    return ans;
}