#include <iostream>
#include <vector>

#define INF ~0U >> 2

using namespace std;
int n, m, temp;
int ans = INF;
bool visited[13];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

void Init();
void FindChickenDistance(int Idx, int Count);
int CheckChickenDistance();

int main()
{
    Init();
    FindChickenDistance(0, 0);
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
                home.push_back({j, i});
            else if(temp == 2)
                chicken.push_back({j, i});
        }
}

void FindChickenDistance(int Idx, int Count)
{
    if(Count == m)
    {
        ans = min(ans,CheckChickenDistance());
        return;
    }
    for(int i = Idx; i < chicken.size(); i++)
    {
        int NextX = chicken[i].first;
        int NextY = chicken[i].second;
        if(!visited[i])
        {
            visited[i] = true;
            FindChickenDistance(i + 1, Count + 1);
            visited[i] = false;
        }
    }
}

int CheckChickenDistance()
{
    int ChickenAns = 0;
    for(int i = 0; i < home.size(); i++)
    {
        int HomeX = home[i].first;
        int HomeY = home[i].second;
        int CurrentDist = INF;
        for(int j = 0; j < chicken.size(); j++)
        {
            int ChickenX = chicken[j].first;
            int ChickenY = chicken[j].second;
            if(visited[j])
                CurrentDist = min(CurrentDist, abs(HomeX - ChickenX) + abs(HomeY - ChickenY));
        }
        ChickenAns += CurrentDist;
    }
    return ChickenAns;
}