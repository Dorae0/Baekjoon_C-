#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
bool IsChecked;
int sudoku_map[9][9];
vector<pii> blanks;

void init();
void sudoku(int CurrentIdx);

int main()
{
    init();
    sudoku(0);
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            scanf("%1d", &sudoku_map[i][j]);
            if(!sudoku_map[i][j])
                blanks.push_back({j, i});
        }
}

void sudoku(int CurrentIdx)
{
    if(IsChecked) return;

    if(CurrentIdx == blanks.size())
    {
        IsChecked = true;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cout << sudoku_map[i][j];
            cout << '\n';
        }
        return;
    }

    int CurrentPosX = blanks[CurrentIdx].first;
    int CurrentPosY = blanks[CurrentIdx].second;

    for(int i = 1; i < 10; i++)
    {
        bool IsValid = true;
        for(int j = 0; j < 9; j++)
            if(sudoku_map[CurrentPosY][j] == i || sudoku_map[j][CurrentPosX] == i)
            {
                IsValid = false;
                break;
            }
        if(!IsValid) continue;
        for(int j = CurrentPosY / 3 * 3; j < CurrentPosY / 3 * 3 + 3; j++)
            for(int k = CurrentPosX / 3 * 3; k < CurrentPosX / 3 * 3 + 3; k++)
                if(sudoku_map[j][k] == i)
                    IsValid = false;
        if(IsValid)
        {
            sudoku_map[CurrentPosY][CurrentPosX] = i;
            sudoku(CurrentIdx + 1);
            sudoku_map[CurrentPosY][CurrentPosX] = 0;
        }
    }
}