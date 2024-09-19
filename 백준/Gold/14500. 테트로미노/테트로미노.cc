#include <iostream>
#define MAX 500

using namespace std;
int n, m;
int map[MAX][MAX];

int dxdy [19][4][2] = 
{
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // I1
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, // I2
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, // O1
    {{0, 0}, {0, -1}, {0, -2}, {1, -2}}, // L1
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}}, // L2
    {{0, 0}, {0, -1}, {1, -1}, {2, -1}}, // L3
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}}, // L4
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, // L5
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, // L6
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, // L7
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, // L8
    {{0, 0}, {0, -1}, {1, -1}, {1, -2}}, // S1
    {{0, 0}, {1, 0}, {1, -1}, {2, -1}}, // S2
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // S3
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, // S4
    {{0, 0}, {-1, 0}, {-1, -1}, {-1, 1}}, // T1
    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}}, // T2
    {{0, 0}, {1, 0}, {1, -1}, {1, 1}}, // T3
    {{0, 0}, {0, -1}, {1, -1}, {-1, -1}}, // T4
};

bool IsValid(int x, int y, int type);
int Calculate(int x, int y, int type);
int Tetromino();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    cout << Tetromino();
}

bool IsValid(int x, int y, int type)
{
    for(int i = 0; i < 4; i++)
    {
        int CurrentX = x + dxdy[type][i][1];
        int CurrentY = y + dxdy[type][i][0];
        if(CurrentX < 0 || m <= CurrentX || CurrentY < 0 || n <= CurrentY)
            return false;
    }
    return true;
}

int Calculate(int x, int y, int type)
{
    int ans = 0;
    for(int i = 0; i < 4; i++)
    {
        int CurrentX = x + dxdy[type][i][1];
        int CurrentY = y + dxdy[type][i][0];
        ans += map[CurrentY][CurrentX];
    }
    return ans;
}

int Tetromino()
{
    int maxValue = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int type = 0; type < 19; type++)
            {
                if(IsValid(j, i, type))
                    maxValue = max(maxValue, Calculate(j, i, type));
            }
    return maxValue;
}