#include <iostream>
#include <queue>
#define MAX 10001

using namespace std;

int n;
int Parent, Sibling, Weight;
int ans, maxNode;
vector<pair<int, int>> vertex[MAX];
queue<int> q;
bool visited[MAX];

void Init();
void SecondInit();
void Backtracking(int Val);

int main()
{
    Init();
    Backtracking(0);
    SecondInit();
    Backtracking(0);
    cout << ans;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> Parent >> Sibling >> Weight;
        vertex[Parent].push_back({Sibling, Weight});
        vertex[Sibling].push_back({Parent, Weight});
    }
    visited[1] = true;
    q.push(1);
}

void SecondInit()
{
    ans = 0;
    for(int i = 0; i < n; i++)
        visited[i] = false;
    while(!q.empty())
        q.pop();
    visited[maxNode] = true;
    q.push(maxNode);
}

void Backtracking(int Val)
{
    while(!q.empty())
    {
        int CurrentNode = q.front();
        q.pop();
        for(int i = 0; i < vertex[CurrentNode].size(); i++)
        {
            int NextNode = vertex[CurrentNode][i].first;
            int NextVal = vertex[CurrentNode][i].second;
            if(!visited[NextNode])
            {
                visited[NextNode] = true;
                q.push(NextNode);
                Backtracking(Val + NextVal);
                visited[NextNode] = false;
            }
        }
        if(ans < Val) maxNode = CurrentNode;
        ans = max(ans, Val);
    }
}