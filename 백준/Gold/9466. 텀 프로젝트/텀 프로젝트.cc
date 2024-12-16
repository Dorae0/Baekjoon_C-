#include <iostream>
#define MAX 100'001

using namespace std;
int t, n, temp, ans;
int nextNode[MAX];
int visited[MAX];
int dist[MAX];

void init();
void arrInit();
void findCycle();

int main()
{
    init();
    for(int i = 0; i < t; i++)
        findCycle();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
}

void arrInit()
{
    for(int i = 1; i <= n; i++)
        visited[i] = 0;
}

void findCycle()
{
    cin >> n;
    arrInit();
    for(int i = 1; i <= n; i++)
        cin >> nextNode[i];
    int currentCycle = 1;
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i])
            continue;
        int currentDist = 1;
        int currentNode = i;
        while(1)
        {
            visited[currentNode] = currentCycle;
            dist[currentNode] = currentDist++;
            if(!visited[nextNode[currentNode]])
                currentNode = nextNode[currentNode];
            else if(visited[nextNode[currentNode]] == currentCycle)
            {
                ans += dist[nextNode[currentNode]] - 1;
                currentCycle++;
                currentDist = 1;
                break;
            }
            else
            {
                ans += currentDist - 1;
                currentCycle++;
                currentDist = 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}