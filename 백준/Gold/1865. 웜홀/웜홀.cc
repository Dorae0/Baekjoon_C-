#include <iostream>
#include <vector>
#define MAX 501
#define INF ~0U >> 2

using namespace std;
int tc, n, m, w, s, e, t; 
int Dist[MAX];
vector<pair<pair<int, int>, int>> edges;

void Init();
void DistInit();
void Solve();
void Bellman_Ford();

int main()
{
    Init();
    for(int i = 0; i < tc; i++)
        Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> tc;
}

void DistInit()
{
    for(int i = 1; i <= n; i++)
        Dist[i] = INF;
}

void Solve()
{
    cin >> n >> m >> w;
    DistInit();
    while(!edges.empty()) edges.pop_back();

    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        edges.push_back({{s, e}, t});
        edges.push_back({{e, s}, t});
    }
    for(int i = 0; i < w; i++)
    {
        cin >> s >> e >> t;
        edges.push_back({{s, e}, -t});
    }
    Bellman_Ford();
}

void Bellman_Ford()
{
    Dist[1] = 0;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < edges.size(); j++)
        {
            int StartNode = edges[j].first.first;
            int EndNode = edges[j].first.second;
            int Weight = edges[j].second;
            if(Dist[EndNode] > Dist[StartNode] + Weight)
                Dist[EndNode] = Dist[StartNode] + Weight;
        }
    
    for(int i = 0; i < edges.size(); i++)
    {
        int StartNode = edges[i].first.first;
        int EndNode = edges[i].first.second;
        int Weight = edges[i].second;
        if(Dist[EndNode] > Dist[StartNode] + Weight)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}