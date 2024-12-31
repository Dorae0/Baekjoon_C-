#include <iostream>
#include <queue>
#define MAX 32001

using namespace std;
int n, m, a, b;
int inDegree[MAX];
bool check[MAX];
vector<int> v[MAX];
vector<int> ans;

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
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
}

void topology_sort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!inDegree[i])
            q.push(i);
    while(!q.empty())
    {
        int currentNode = q.front();
        ans.push_back(currentNode);
        check[currentNode] = true;
        q.pop();
        for(int i = 0; i < v[currentNode].size(); i++)
        {
            int nextNode = v[currentNode][i];
            inDegree[nextNode]--;
            if(!inDegree[nextNode])
                q.push(nextNode);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!check[i])
            ans.push_back(i);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}