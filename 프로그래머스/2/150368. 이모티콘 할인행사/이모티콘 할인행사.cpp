#include <string>
#include <vector>
#include <queue>

using namespace std;
int m;
int salePercent[7];

void SelectEmoticons(vector<vector<int>> users, vector<int> emoticons, int Count);
void CheckPlus(vector<vector<int>> users, vector<int> emoticons);
priority_queue<pair<int, int>> pq;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    m = emoticons.size();
    SelectEmoticons(users, emoticons, 0);
    answer.push_back(pq.top().first);
    answer.push_back(pq.top().second);
    return answer;
}

void SelectEmoticons(vector<vector<int>> users, vector<int> emoticons, int Count)
{
    if(Count == emoticons.size())
    {
        CheckPlus(users, emoticons);
        return;
    }
    for(int i = 1; i <= 4; i++)
    {
        salePercent[Count] = i;
        SelectEmoticons(users, emoticons, Count + 1);
    }
}

void CheckPlus(vector<vector<int>> users, vector<int> emoticons)
{
    int AllPrice = 0;
    int AllEmoticonPlus = 0;
    for(int i = 0; i < users.size(); i++)
    {
        int UserRatio = users[i][0];
        int UserPrice = users[i][1];
        int CurrentPrice = 0;
        for(int j = 0; j < emoticons.size(); j++)
        {
            int EmoticonRatio = salePercent[j] * 10;
            int EmoticonPrice = emoticons[j] * (10 - salePercent[j]) / 10;
            if(UserRatio <= EmoticonRatio)
                CurrentPrice += EmoticonPrice;
            if(CurrentPrice >= UserPrice)
            {
                CurrentPrice = 0;
                AllEmoticonPlus++;
                break;
            }
        }
        AllPrice += CurrentPrice;
    }
    pq.push({AllEmoticonPlus, AllPrice});
}