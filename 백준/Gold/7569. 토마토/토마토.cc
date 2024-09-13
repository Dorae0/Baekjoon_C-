#include <iostream>
#include <tuple>
#define MAX 100
#define MAX3 1000000
using namespace std;

int map[100][100][100];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, h, TomatoNum, countNum, ans;
tuple<int, int, int> v[MAX3];
tuple<int, int, int> prev_v[MAX3];

bool PlayTurn(bool isInitial);
bool IsValid(int x, int y, int z);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                {
                    cin >> map[k][j][i];
                    if(map[k][j][i] == 0)
                        TomatoNum++;
                }

    while(1)
    {
        bool Value = true;
        if(countNum)
            Value = PlayTurn(false);
        else
            Value = PlayTurn(true);
        if(!Value) break;
        countNum++;
    };

    if(TomatoNum) cout << -1;
    else cout << countNum;
}

bool PlayTurn(bool isInitial)
{
    if(isInitial)  
    {
        for(int i = 0; i < h; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < m; k++)
                    if(map[k][j][i] == 1)
                    {
                        for(int l = 0; l < 6; l++)
                        {
                            if(IsValid(k + dx[l], j + dy[l], i + dz[l]) && map[k + dx[l]][j + dy[l]][i + dz[l]] == 0)
                            {
                                map[k + dx[l]][j + dy[l]][i + dz[l]] = 2;
                                v[ans] = make_tuple(k + dx[l], j + dy[l], i + dz[l]);
                                ans++;
                            }
                        }
                    }
    }
    else
    {
        int prev_ans = ans;
        ans = 0;
        for(int i = 0; i < prev_ans; i++)
        {
            int CurrentX = get<0>(prev_v[i]); int CurrentY = get<1>(prev_v[i]); int CurrentZ = get<2>(prev_v[i]);
            for(int l = 0; l < 6; l++)
            {
                if(IsValid(CurrentX + dx[l], CurrentY + dy[l], CurrentZ + dz[l]) && map[CurrentX + dx[l]][CurrentY + dy[l]][CurrentZ + dz[l]] == 0)
                {
                    map[CurrentX + dx[l]][CurrentY + dy[l]][CurrentZ + dz[l]] = 2;
                    v[ans] = make_tuple(CurrentX + dx[l], CurrentY + dy[l], CurrentZ + dz[l]);
                    ans++;
                }
            }
        }   
    }
    if(!ans) return false;
    else
    {   
        for(int i = 0; i < ans; i++)
        {
            map[get<0>(v[i])][get<1>(v[i])][get<2>(v[i])] = 1;
            prev_v[i] = v[i];
        }
        TomatoNum -= ans;
        return true;
    }
}

bool IsValid(int x, int y, int z)
{
    if(x > -1 && x < m && y > -1 && y < n && z > -1 && z < h)
        return true;
    else
        return false;
}