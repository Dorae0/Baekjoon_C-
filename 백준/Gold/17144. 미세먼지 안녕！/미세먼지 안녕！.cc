#include <iostream>
#define MAX 50

using namespace std;
int r, c, t;
int map[MAX][MAX];
int map_temp[MAX][MAX];
int purifier[2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void mapInit();
void init();
bool isValid(int PosX, int PosY);
void diffusion();
void purify();
void print();

int main()
{
    init();
    for(int i = 0; i < t; i++)
    {
        diffusion();
        purify();
    }
    print();
}

void mapInit()
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            map_temp[i][j] = 0;
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1)
            {
                if(!purifier[0])
                    purifier[0] = i;
                else
                    purifier[1] = i;
            }
        }
}

bool isValid(int PosX, int PosY)
{
    if(PosY >= 0 && PosY < r && PosX >= 0 && PosX < c)
    {
        if(map[PosY][PosX] == -1)
            return false;
        return true;
    }
    return false;
}

void diffusion()
{
    mapInit();
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(map[i][j] > 0)
                for(int k = 0; k < 4; k++)
                    if(isValid(j + dx[k], i + dy[k]))
                    {
                        map_temp[i][j] -= map[i][j] / 5;
                        map_temp[i + dy[k]][j + dx[k]] += map[i][j] / 5;
                    }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            map[i][j] += map_temp[i][j];
}

void purify()
{
    for(int i = purifier[0] - 2; i >= 0; i--)
        map[i + 1][0] = map[i][0];
    for(int i = purifier[1] + 2; i < r; i++)
        map[i - 1][0] = map[i][0];

    for(int i = 1; i < c; i++)
    {
        map[0][i - 1] = map[0][i];
        map[r - 1][i - 1] = map[r - 1][i];
    }

    for(int i = 1; i <= purifier[0]; i++)
        map[i - 1][c - 1] = map[i][c - 1];
    for(int i = r - 2; i >= purifier[1]; i--)
        map[i + 1][c - 1] = map[i][c - 1];

    for(int i = c - 2; i >= 1; i--)
    {
        map[purifier[0]][i + 1] = map[purifier[0]][i];
        map[purifier[1]][i + 1] = map[purifier[1]][i];
    }
    map[purifier[0]][1] = 0;
    map[purifier[1]][1] = 0;
}

void print()
{
    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            ans+= map[i][j];
    ans+= 2;
    cout << ans;
}