#include <iostream>
#include <list>
#define MAX 1001

using namespace std;

enum directions {
    DIRECTION_UP = 1,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_LEFT,
    DIRECTION_MAX
};

struct shark {
    int posY;
    int posX;
    int speed;
    int direction;
    int size;
    int moveCount = 0;
};

int R, C, m, r, c, s, d, z, ans;
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, -1, 1, 0, 0 };
list<shark>::iterator map[MAX][MAX];
list<shark> sharks;

void Init();
void Fishing(int i);
bool IsValid(int y, int x);
int DirectionChange(int direction);
void Move();
void FishingKing();

int main()
{
    Init();
    FishingKing();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> R >> C >> m;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            map[i][j] = sharks.end();

    for (int i = 1; i <= m; i++)
    {
        cin >> r >> c >> s >> d >> z;
        sharks.push_back(shark{ r, c, s, d, z });
        list<shark>::iterator it = sharks.end();
        it--;
        map[r][c] = it;
    }
}

void Fishing(int i)
{
    for (int j = 1; j <= R; j++)
    {
        if (map[j][i] != sharks.end())
        {
            ans += map[j][i]->size;
            sharks.erase(map[j][i]);
            map[j][i] = sharks.end();
            return;
        }
    }
}

bool IsValid(int y, int x)
{
    if (y >= 1 && y <= R && x >= 1 && x <= C)
        return true;
    return false;
}

int DirectionChange(int direction)
{
    switch (direction)
    {
    case DIRECTION_UP:
        return DIRECTION_DOWN;
    case DIRECTION_DOWN:
        return DIRECTION_UP;
    case DIRECTION_LEFT:
        return DIRECTION_RIGHT;
    case DIRECTION_RIGHT:
        return DIRECTION_LEFT;
    }
}

void Move()
{
    list<shark>::iterator it = sharks.begin();
    while (it != sharks.end())
    {
        if(map[it->posY][it->posX] == it)
            map[it->posY][it->posX] = sharks.end();
        int divider = ((C - 1) * 2);
        int nextPosY = it->posY, nextPosX = it->posX;
        if (it->direction == DIRECTION_UP || it->direction == DIRECTION_DOWN)
            divider = ((R - 1) * 2);
        if (it->speed != 0)
        {
            for (int i = 0; i < (it->speed - 1) % divider + 1; i++)
            {
                nextPosY = it->posY + dy[it->direction];
                nextPosX = it->posX + dx[it->direction];
                if (!IsValid(nextPosY, nextPosX))
                {
                    it->direction = DirectionChange(it->direction);
                    nextPosY = it->posY + dy[it->direction];
                    nextPosX = it->posX + dx[it->direction];
                }
                it->posY = nextPosY;
                it->posX = nextPosX;
            }
        }
        it->moveCount++;
        if (map[nextPosY][nextPosX] != sharks.end() && map[nextPosY][nextPosX]->moveCount == it->moveCount)
        {
            if (it->size > map[nextPosY][nextPosX]->size)
            {
                sharks.erase(map[nextPosY][nextPosX]);
                map[nextPosY][nextPosX] = it;
            }
            else
            {
                list<shark>::iterator temp_it = it;
                it = sharks.erase(temp_it);
                continue;
            }
        }
        else
            map[nextPosY][nextPosX] = it;
        it++;
    }
}

void FishingKing()
{
    for (int i = 1; i <= C; i++)
    {
        Fishing(i);
        Move();
    }
    cout << ans;
}