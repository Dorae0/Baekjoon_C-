#include <iostream>
#include <vector>
#define MAX 51
#define INF ~0U >> 2

using namespace std;
int n, startNode, endNode, minVal = INF;
vector<int> edges[MAX];
vector<int> presidents;
int dist[MAX][MAX];

void Init();
void DistInit();
void Floyd_Warshall();
void FindMinVal();

int main()
{
    Init();
    Floyd_Warshall();
    FindMinVal();
}

void DistInit()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == j) dist[i][j] = 1;
            else dist[i][j] = INF;
        }
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    DistInit();
    while(1)
    {
        cin >> startNode >> endNode;
        if(startNode == -1) break;
        edges[startNode].push_back(endNode);
        edges[endNode].push_back(startNode);
        dist[startNode][endNode] = 1;
        dist[endNode][startNode] = 1;
    }
}

void Floyd_Warshall()
{
    for(int node = 1; node <= n; node++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][j] > dist[i][node] + dist[node][j])
                    dist[i][j] = dist[i][node] + dist[node][j];
} 

void FindMinVal()
{
    for(int i = 1; i <= n; i++)
    {
        int CurrentVal = 0;
        for(int j = 1; j <= n; j++)
            CurrentVal = max(CurrentVal, dist[i][j]);
        if(minVal > CurrentVal)
        {
            minVal = CurrentVal;
            while(!presidents.empty())
                presidents.pop_back();
            presidents.push_back(i);
        }
        else if(minVal == CurrentVal)
            presidents.push_back(i);
    }
    cout << minVal << ' ' << presidents.size() << '\n';
    for(int i = 0; i < presidents.size(); i++)
        cout << presidents[i] << ' ';
}