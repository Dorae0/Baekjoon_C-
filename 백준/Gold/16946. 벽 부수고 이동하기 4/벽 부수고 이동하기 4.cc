#include <iostream>
#include <string>
#include <queue>
#define MAX 1001

using namespace std;
int n, m, map[MAX][MAX], groupNum[MAX][MAX], ans[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int previousGroupNum[3];
bool visited[MAX][MAX];
string s;
queue<pair<int, int>> q;

void Init();
bool IsValid(pair<int, int> pos);
void CountGroup();
void BreakWall();

int main()
{
    Init();
    CountGroup();
    BreakWall();
}

void Init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
            if (map[i][j] == 1)
                map[i][j] = -1;
        }
    }
}

bool IsValid(pair<int, int> pos)
{
    if (pos.second >= 0 && pos.second < m && pos.first >= 0 && pos.first < n)
        return true;
    return false;
}

void CountGroup()
{
    int groupN = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] >= 0 && !visited[i][j])
            {
                groupN++;
                q.push({ i, j });
                count = 1;
                while (!q.empty())
                {
                    pair<int, int> currentPos = q.front();
                    q.pop();
                    visited[currentPos.first][currentPos.second] = true;
                    groupNum[currentPos.first][currentPos.second] = groupN;
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> nextPos = { currentPos.first + dy[k], currentPos.second + dx[k] };
                        if (IsValid(nextPos) && !visited[nextPos.first][nextPos.second] && map[nextPos.first][nextPos.second] != -1)
                        {
                            visited[nextPos.first][nextPos.second] = true;
                            groupNum[nextPos.first][nextPos.second] = groupN;
                            q.push(nextPos);
                            count++;
                        }
                    }
                }
                q.push({ i, j });
                while (!q.empty())
                {
                    pair<int, int> currentPos = q.front();
                    q.pop();
                    map[currentPos.first][currentPos.second] = count;
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> nextPos = { currentPos.first + dy[k], currentPos.second + dx[k] };
                        if (IsValid(nextPos) && !map[nextPos.first][nextPos.second])
                        {
                            map[nextPos.first][nextPos.second] = count;
                            q.push(nextPos);
                        }
                    }
                }
            }
}

void BreakWall()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == -1)
            {
                int currentAns = 1;
                for (int k = 0; k < 4; k++)
                {
                    previousGroupNum[k] = groupNum[i + dy[k]][j + dx[k]];
                    if (IsValid({ i + dy[k], j + dx[k] }) && map[i + dy[k]][j + dx[k]] != -1)
                    {
                        bool isValid = true;
                        for (int l = 0; l < k; l++)
                        {
                            if (previousGroupNum[l] == groupNum[i + dy[k]][j + dx[k]])
                            {
                                isValid = false;
                                break;
                            }
                        }
                        if (isValid)
                            currentAns += map[i + dy[k]][j + dx[k]];
                    }
                }
                ans[i][j] = currentAns % 10;
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}