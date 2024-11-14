#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;
int n, k;
queue<pair<int, int>> q;
bool visited[MAX];

void Init();
void BFS();

int main()
{
    Init();
    BFS();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
}

void BFS()
{
    q.push({n, 0});
    int answerDist = 0;
    int answerQuantity = 0;

    while(!q.empty())
    {
        int CurrentPos = q.front().first;
        int CurrentDist = q.front().second;
        visited[CurrentPos] = true;
        if(answerDist != 0 && CurrentDist > answerDist)
            break;
        if(answerDist == 0 && CurrentPos == k)
        {
            answerDist = CurrentDist;
            answerQuantity++;
        }
        else if(CurrentPos == k && answerDist == CurrentDist)
            answerQuantity++;
        q.pop();

        int NextPos;

        for(int i = 0; i < 3; i++)
        {
            if(i == 0)
                NextPos = CurrentPos - 1;
            else if(i == 1)
                NextPos = CurrentPos + 1;
            else
                NextPos = CurrentPos * 2;
            
            if(NextPos >= 0 && NextPos < MAX)
            {
                if(!visited[NextPos])
                    q.push({NextPos, CurrentDist + 1});
            }
        }
    }
    cout << answerDist << '\n' << answerQuantity;
}