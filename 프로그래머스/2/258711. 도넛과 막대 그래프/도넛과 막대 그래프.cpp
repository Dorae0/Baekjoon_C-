#include <string>
#include <vector>
#include <queue>
#define MAX 1000001

using namespace std;

int Graph_Donut, Graph_Bar, Graph_Eight;
int Node_Out[MAX];
int Node_In[MAX];
vector<vector<int>> path(MAX);
queue<int> q;

int InitializeNode(vector<vector<int>> edges);
void SearchGraph();

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int AttachedNode = InitializeNode(edges);
    answer.push_back(AttachedNode);
    for(int i = 0 ; i < path[AttachedNode].size(); i++)
    {
        q.push(path[AttachedNode][i]);
        SearchGraph();
    }
    answer.push_back(Graph_Donut);
    answer.push_back(Graph_Bar);
    answer.push_back(Graph_Eight);
    return answer;
}

int InitializeNode(vector<vector<int>> edges)
{
    int AttachedNode;
    for(int i = 0; i < edges.size(); i++)
    {
        Node_Out[edges[i][0]]++;
        Node_In[edges[i][1]]++;
        path[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i = 1; i < MAX; i++)
    {
        if(Node_Out[i] >= 2 && Node_In[i] == 0)
        {
            AttachedNode = i;
            break;
        }
    }
    return AttachedNode;
}

void SearchGraph()
{
    int CurrentNode;
    int NextNode;
    int InitialNode = q.front();
    
    while(!q.empty())
    {
        CurrentNode = q.front();
        q.pop();
        if(path[CurrentNode].size() == 2)
        {
            Graph_Eight++;
            return;
        }
        for(int i = 0; i < path[CurrentNode].size(); i++)
        {
            NextNode = path[CurrentNode][i];
            if(NextNode == InitialNode)
            {
                Graph_Donut++;
                return;
            }
            else
                q.push(NextNode);
        }
    }
    Graph_Bar++;
    return;
}