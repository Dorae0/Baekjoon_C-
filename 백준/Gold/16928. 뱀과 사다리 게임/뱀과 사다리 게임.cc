#include <iostream>
#include <queue>
#define MAX 30

using namespace std;

queue<pair<int, int>> q;
pair<int, int> arr[MAX];
int n, m, x, y;
int ans;
bool visited[101];

void bfs();
int search(int x);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++)
    {
        cin >> x >> y;
        arr[i] = {x, y};
    }
    bfs();
    cout << ans;
}

void bfs()
{
    q.push({1, 0});
    while(!q.empty())
    {
        int currentNum = q.front().first;
        int currentCount = q.front().second;
        q.pop();
        for(int i = 1; i < 7; i++)
        {
            int nextNum = currentNum + i;
            if(nextNum > 100) continue;
            if(nextNum == 100)
            {
                ans = currentCount + 1;
                return;
            }
            int arrNum = search(nextNum);
            if(arrNum != -1)
                nextNum = arrNum;
            if(!visited[nextNum])
            {
                visited[nextNum] = true;
                q.push({nextNum, currentCount + 1});
            }
        }
    }
}

int search(int x)
{
    for(int i = 0; i < n + m; i++)
        if(arr[i].first == x)
            return arr[i].second;
    return -1;
}