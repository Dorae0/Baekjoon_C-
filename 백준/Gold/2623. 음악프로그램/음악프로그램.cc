#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;
int n, m, t;
int inDegree[MAX];
vector<int> v[MAX];
vector<int> topology;
int order[MAX];

void init();
void topology_sort();

int main()
{
    init();
    topology_sort();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> t;
        for(int j = 0; j < t; j++)
            cin >> order[j];
        for(int j = 1; j < t; j++)
        {
            v[order[j - 1]].push_back(order[j]);
            inDegree[order[j]]++;
        }
    }
}

void topology_sort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!inDegree[i])
            q.push(i);
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            cout << 0;
            return;
        }
        int currentSinger = q.front();
        q.pop();
        topology.push_back(currentSinger);
        for(int j = 0; j < v[currentSinger].size(); j++)
        {
            int nextSinger = v[currentSinger][j];
            inDegree[nextSinger]--;
            if(!inDegree[nextSinger])
                q.push(nextSinger);
        }
    }
    for(int i = 0; i < topology.size(); i++)
        cout << topology[i] << '\n';
}