#include <iostream>
#include <vector>
#define MAX 9

using namespace std;
int n, temp[4], temp2[4];
bool dices[MAX][MAX];
bool dice_check[MAX];
int dice_count[MAX];
vector<vector<int>> dice_log[MAX];

void init();
void rollDice();
bool checkLog(int dices[4]);

int main()
{
    init();
    rollDice();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

bool checkLog(int dice[4])
{
    for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                if(!dices[dice[j]][dice[k]])
                {
                    dices[dice[j]][dice[k]] = true;
                    dice_count[dice[j]]++;
                    if(dice_count[dice[j]] == 8)
                        return false;
                }
    for(int i = 0; i < 4; i++)
    {
        int currentDice = dice[i];
        if(dice_log[currentDice].empty())
        {
            vector<int> temp_dices;
            for(int k = 0; k < 4; k++)
            {
                if(i == k) continue;
                temp_dices.push_back(dice[k]);
            }
            dice_log[currentDice].push_back(temp_dices);
        }
        else
        {
            bool isChecked = false;
            for(int j = 0; j < dice_log[currentDice].size(); j++)
            {
                int checkCount = 0;
                for(int k = 0; k < 4; k++)
                {
                    if(i == k) continue;
                    for(int l = 0; l < 3; l++)
                        if(dice[k] == dice_log[currentDice][j][l])
                            checkCount++;
                }
                if(checkCount == 3)
                    isChecked = true;
                if(checkCount == 0 || checkCount == 2)
                    return false;
            }
            if(!isChecked)
            {
                if(dice_log[currentDice].size() >= 4)
                    return false;
                vector<int> temp_dices;
                for(int k = 0; k < 4; k++)
                {
                    if(i == k) continue;
                    temp_dices.push_back(dice[k]);
                }
                dice_log[currentDice].push_back(temp_dices);
            }
        }
    }
    return true;
}

void rollDice()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < MAX; j++)
            dice_check[j] = false;
        for(int j = 0; j < 4; j++)
        {
            cin >> temp[j];
            dice_check[temp[j]] = true;
        }
        int tempIdx = 0;
        for(int j = 1; j < MAX; j++)
            if(!dice_check[j])
                temp2[tempIdx++] = j;
        if(!checkLog(temp))
        {
            cout << "You're gonna die!";
            return;
        }
        if(!checkLog(temp2))
        {
            cout << "You're gonna die!";
            return;
        }
    }
    cout << "Hmm...";
}