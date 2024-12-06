#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;
int t, n, k, x, y, w;
int d[MAX];
int ans[MAX];
int inDegree[MAX];
vector<int> topology;
vector<int> v[MAX];
vector<int> v_reverse[MAX];

void init();
void arr_init();
void ACMCraft();
void topology_sort();

int main()
{
    init();
    ACMCraft();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
}

void arr_init()
{
    for(int i = 1; i <= n; i++)
    {
        inDegree[i] = 0;
        ans[i] = 0;
        d[i] = 0;
        while(!v[i].empty())
            v[i].pop_back();
        while(!v_reverse[i].empty())
            v_reverse[i].pop_back();
    }
    while(!topology.empty())
        topology.pop_back();
}

void ACMCraft()
{
    for(int i = 0; i < t; i++)
    {
        arr_init();
        cin >> n >> k;
        for(int j = 1; j <= n; j++)
            cin >> d[j];
        for(int j = 0; j < k; j++)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v_reverse[y].push_back(x);
            inDegree[y]++;
        }
        cin >> w;
        topology_sort();
        for(int j = 0; j < topology.size(); j++)
        {
            int currentStructure = topology[j];
            int maxVal = 0;
            for(int k = 0; k < v_reverse[currentStructure].size(); k++)
                maxVal = max(maxVal, ans[v_reverse[currentStructure][k]]);
            ans[currentStructure] = maxVal + d[currentStructure];
            if(currentStructure == w)
            {
                cout << ans[currentStructure] << '\n';
                break;
            }
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
            return;
        int currentNode = q.front();
        q.pop();
        topology.push_back(currentNode);
        for(int i = 0; i < v[currentNode].size(); i++)
        {
            int nextNode = v[currentNode][i];
            inDegree[nextNode]--;
            if(!inDegree[nextNode])
                q.push(nextNode);
        }
    }
}