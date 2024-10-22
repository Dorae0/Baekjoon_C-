#include <iostream>
#define MAX 101
#define INF ~0U >> 2

using namespace std;
int m, n, x, y, w;
int map[MAX][MAX];
void Init();
void Floyd();
void Print();

int main()
{
    Init();
    Floyd();
    Print();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            {
                if(i == j) map[i][j] = 0;
                else map[i][j] = INF;
            }

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> y >> x >> w;
        map[y][x] = min(map[y][x], w);
    }
}

void Floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
}

void Print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == INF) map[i][j] = 0;
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }   
}