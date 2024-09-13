#include <iostream>
#include <queue>
#include <string>
#define MAX 100

using namespace std;
int n, ans, ans_blinded;
string map[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
bool visited[MAX][MAX];
bool visited_blinded[MAX][MAX];

bool IsValid(int x, int y);
void RGB(int x, int y);
void RGB_BLIND(int x, int y);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
            cin >> map[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            {
                if(!visited[i][j])
                {
                    RGB(i, j);
                    ans++;
                }
                if(!visited_blinded[i][j])
                {
                    RGB_BLIND(i, j);
                    ans_blinded++;
                }
            }
    
    cout << ans << ' ' << ans_blinded;
}

bool IsValid(int x, int y)
{
    if(x > -1 && x < n && y > -1 && y < n)
        return true;
    else
        return false;
}

void RGB(int x, int y)
{
    q.push({x, y});
    while(!q.empty())
    {
        int currentPosX = q.front().first;
        int currentPosY = q.front().second;
        char currentFieldColor = map[currentPosX][currentPosY];
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int movingPosX = currentPosX + dx[i];
            int movingPosY = currentPosY + dy[i];
            char movingFieldColor = map[movingPosX][movingPosY];
            if(IsValid(movingPosX,movingPosY) && visited[movingPosX][movingPosY] == false && currentFieldColor == movingFieldColor)
            {
                visited[movingPosX][movingPosY] = true;
                RGB(movingPosX, movingPosY);
            }
        }
    }
}

void RGB_BLIND(int x, int y)
{
    q.push({x, y});
    while(!q.empty())
    {
        int currentPosX = q.front().first;
        int currentPosY = q.front().second;
        char currentFieldColor = map[currentPosX][currentPosY];
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int movingPosX = currentPosX + dx[i];
            int movingPosY = currentPosY + dy[i];
            char movingFieldColor = map[movingPosX][movingPosY];
            if(IsValid(movingPosX,movingPosY) && visited_blinded[movingPosX][movingPosY] == false && (currentFieldColor == movingFieldColor || (currentFieldColor != 'B' && movingFieldColor != 'B')))
            {
                visited_blinded[movingPosX][movingPosY] = true;
                RGB_BLIND(movingPosX, movingPosY);
            }
        }
    }
}