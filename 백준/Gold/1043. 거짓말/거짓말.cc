#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

using namespace std;

int n, m, people, pNum;
bool IsKnown[MAX];
vector<vector<int>> party;
vector<int> edges[MAX];
queue<int> peoples;

void Init();
void FindPeople();
int FindParty();

int main()
{
    Init();
    FindPeople();
    cout << FindParty();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> people;
    for(int i = 0; i < people; i++)
    {
        cin >> pNum;
        IsKnown[pNum] = true;
        peoples.push(pNum);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> people;
        vector<int> CurrentParty;
        for(int j = 0; j < people; j++)
        {
            cin >> pNum;
            CurrentParty.push_back(pNum);
        }
        for(int j = 0; j < CurrentParty.size(); j++)
        {
            int StartNode = CurrentParty[j];
            for(int k = j + 1; k < CurrentParty.size(); k++)
            {
                int EndNode = CurrentParty[k];
                edges[StartNode].push_back(EndNode);
                edges[EndNode].push_back(StartNode);
            }
        }
        party.push_back(CurrentParty);
    }
}

void FindPeople()
{
    while(!peoples.empty())
    {
        int CurrentPeople = peoples.front();
        peoples.pop();
        for(int i = 0; i < edges[CurrentPeople].size(); i++)
        {
            int NextPeople = edges[CurrentPeople][i];
            if(!IsKnown[NextPeople])
            {
                IsKnown[NextPeople] = true;
                peoples.push(NextPeople);
            }
        }
    }
}

int FindParty()
{
    int ans = 0;
    for(int i = 0; i < party.size(); i++)
    {
        bool IsValid = true;
        for(int j = 0; j < party[i].size(); j++)
        {
            if(IsKnown[party[i][j]])
            {
                IsValid = false;
                break;
            }
        }
        if(IsValid) ans++;
    }
    return ans;
}