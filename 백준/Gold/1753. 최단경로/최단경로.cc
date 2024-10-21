#include <iostream>
#include <queue>
#define MAX 20001
#define INF ~0U >> 2

using namespace std;
int v, e, start;
int x, y, w;
vector<pair<int, int>> vertex[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int Value[MAX];

void Init();
void Dijkstra();
void Print();

int main()
{
    Init();
    Dijkstra();
    Print();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < MAX; i++)
        Value[i] = INF;

    cin >> v >> e >> start;
    for(int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        vertex[x].push_back({w, y});
    }
}

void Dijkstra()
{
    pq.push({0, start});
    Value[start] = 0;
    while(!pq.empty())
    {
        int CurrentValue = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();
        for(int i = 0; i < vertex[CurrentNode].size(); i++)
        {
            int NextValue = vertex[CurrentNode][i].first;
            int NextNode = vertex[CurrentNode][i].second;
            if(Value[NextNode] > CurrentValue + NextValue)
            {
                Value[NextNode] = CurrentValue + NextValue;
                pq.push({Value[NextNode], NextNode});
            }
        }
    }
}

void Print()
{
    for(int i = 1; i <= v; i++)
    {
        if(Value[i] == INF)
            cout << "INF" << '\n';
        else
            cout << Value[i] << '\n';
    }
}