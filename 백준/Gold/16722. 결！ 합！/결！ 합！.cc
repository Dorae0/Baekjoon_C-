#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 100

using namespace std;

struct info{
    string type;
    string bg;
    string color;
};

int n, firstN, secondN, thirdN;
bool isG = false;
char gametype;
info board[10];
bool visited[10];
string type, bg, color;
vector<vector<int>> answers;

void init();
void checkAnswer(int Count, int Idx);
bool isCorrect(int firstN, int secondN, int thirdN, int type);
void game();

int main()
{
    init();
    checkAnswer(0, 1);
    game();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 1; i < 10; i++)
    {
        cin >> type >> bg >> color;
        board[i] = {type, bg, color};
    }
    cin >> n;
}

bool isCorrect(int firstN, int secondN, int thirdN, int type)
{
    if(type == 0)
        if((board[firstN].type == board[secondN].type && board[thirdN].type == board[secondN].type)|| (board[firstN].type != board[secondN].type && board[secondN].type != board[thirdN].type && board[firstN].type != board[thirdN].type))
            return true;
        else
            return false;
    else if(type == 1)
        if((board[firstN].color == board[secondN].color && board[thirdN].color == board[secondN].color) || (board[firstN].color != board[secondN].color && board[secondN].color != board[thirdN].color && board[firstN].color != board[thirdN].color))
            return true;
        else
            return false;
    else
        if((board[firstN].bg == board[secondN].bg && board[thirdN].bg == board[secondN].bg) || (board[firstN].bg != board[secondN].bg && board[secondN].bg != board[thirdN].bg && board[firstN].bg != board[thirdN].bg))
            return true;
        else
            return false;
}

void checkAnswer(int Count, int Idx)
{
    if(Count == 3)
    {
        int firstAns = -1;
        int secondAns = -1;
        int thirdAns = -1;
        for(int i = 1; i < 10; i++)
        {
            if(!visited[i]) continue;
            if(firstAns < 0)
                firstAns = i;
            else if(secondAns < 0)
                secondAns = i;
            else if(thirdAns < 0)
                thirdAns = i;
        }
        for(int i = 0; i < 3; i++)
            if(!isCorrect(firstAns, secondAns, thirdAns, i))
                return;
        for(int i = 0; i < answers.size(); i++)
            if(answers[i][0] == firstAns && answers[i][1] == secondAns && answers[i][2] == thirdAns)
                return;
        answers.push_back({firstAns, secondAns, thirdAns});
    }
    for(int i = Idx; i < 10; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            checkAnswer(Count + 1, Idx + 1);
            visited[i] = false;
        }
    }
}

void game()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> gametype;
        if(gametype == 'H')
        {
            vector<int> numbers;
            cin >> firstN >> secondN >> thirdN;
            numbers.push_back(firstN);
            numbers.push_back(secondN);
            numbers.push_back(thirdN);
            sort(numbers.begin(), numbers.end());
            bool checkType = true;
            bool checkColor = true;
            bool checkBg = true;
            bool currentAns = true;
            for(int j = 0; j < 3; j++)
                if(!isCorrect(firstN, secondN, thirdN, j))
                {
                    ans--;
                    currentAns = false;
                    break;
                }
            if(!currentAns)
                continue;
            for(int j = 0; j < answers.size(); j++)
            {
                bool isChecked = true;
                for(int k = 0; k < 3; k++)
                    if(answers[j][k] != numbers[k])
                    {
                        isChecked = false;
                        break;
                    }
                if(isChecked)
                {
                    answers.erase(answers.begin() + j);
                    ans += 2;
                    break;
                }
            }
            ans--;
        }
        else if(gametype == 'G')
        {
            if(answers.empty() && !isG)
            {
                isG = true;
                ans += 3;
            }
            else
                ans --;
        }
    }
    cout << ans;
}