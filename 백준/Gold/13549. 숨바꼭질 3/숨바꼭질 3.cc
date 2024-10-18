#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;
int n, k;
int CurrentTime, CurrentNode, NextTime, NextNode;
priority_queue<pair<int, int>> pq;
int Time[MAX];
int dx[2] = {1, -1};

void Init();
void Dijkstra();

int main()
{
    Init();
    Dijkstra();
    return 0;
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < MAX; i++)
        Time[i] = -1;
    cin >> n >> k;
    pq.push({0, n});
    Time[n] = 0;
}

void Dijkstra()
{
    while(!pq.empty())
    {
        CurrentTime = -pq.top().first;
        CurrentNode = pq.top().second;
        pq.pop();
        if(CurrentTime > Time[CurrentNode])
            continue;
        for(int i = 0; i < 3; i++)
        {
            if(i == 2)
            {
                NextNode = 2 * CurrentNode;
                NextTime = CurrentTime;
            }
            else
            {
                NextNode = CurrentNode + dx[i];
                NextTime = CurrentTime + 1;
            }
            if(NextNode < 0 || NextNode > 100000)
                continue;
            if(Time[NextNode] == -1 || Time[NextNode] > NextTime)
            {
                Time[NextNode] = NextTime;
                pq.push({-NextTime, NextNode});
            }
        }
    }
    cout << Time[k];
}