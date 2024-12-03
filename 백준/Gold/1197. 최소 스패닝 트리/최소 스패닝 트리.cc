#include <iostream>
#include <queue>
#define MAX 10001

using namespace std;
using pii = pair<int, int>;

int v, e, a, b, c;
bool visited[MAX];
vector<pii> edges[MAX];
priority_queue <pii, vector<pii>, greater<pii>> pq;

void init();
int prim();

int main()
{
    init();
    cout << prim();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        if(i == 0)
            pq.push({0, a});
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }
}

int prim()
{
    int ans = 0;
    int count = 0;
    while(!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if(visited[currentNode])
            continue;
        visited[currentNode] = true;    
        ans += currentDist;
        count++;
        if(count >= v)
            break;
        for(int i = 0; i < edges[currentNode].size(); i++)
        {
            int nextDist = edges[currentNode][i].first;
            int nextNode = edges[currentNode][i].second;
            if(!visited[nextNode])
                pq.push({nextDist, nextNode});
        }
    }
    return ans;
}