#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 500

using namespace std;
bool temp_count[MAX];
int oils[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int posX, int posY, vector<vector<int>> land);
int drilling(vector<vector<int>> land);

int solution(vector<vector<int>> land) {
    return drilling(land);
}

bool isValid(int posX, int posY, int maxX, int maxY)
{
    if(posX >= 0 && posX < maxX && posY >= 0 && posY < maxY) 
        return true;
    return false;
}

int drilling(vector<vector<int>> land)
{
    for(int i = 0; i < land.size(); i++)
        for(int j = 0; j < land[0].size(); j++)
        {
            int width = 0;
            if(land[i][j] == 0) continue;
            land[i][j] = 0;
            queue<pair<int, int>> q;
            q.push({j, i});
            while(!q.empty())
            {
                int currentPosX = q.front().first;
                int currentPosY = q.front().second;
                width++;
                temp_count[currentPosX] = true;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nextPosX = currentPosX + dx[i];
                    int nextPosY = currentPosY + dy[i];
                    if(isValid(nextPosX, nextPosY, land[0].size(), land.size()) && land[nextPosY][nextPosX])
                    {
                        q.push({nextPosX, nextPosY});
                        land[nextPosY][nextPosX] = 0;
                    }
                }
            }
            for(int i = 0; i < land[0].size(); i++)
                if(temp_count[i])
                {
                    oils[i] += width;
                    temp_count[i] = false;
                }
        }
    sort(oils, oils + land[0].size());
    return oils[land[0].size() - 1];
}