#include <string>
#include <vector>
#include <stack>
#define MAX 1000001

using namespace std;
vector<int> node_in[MAX];
vector<int> node_out[MAX];
stack<int> s;
int graph_donut, graph_bar, graph_eight;

void VectorInit(vector<vector<int>> edges);
int FindStartNode();
void FindGraph(int Node);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    VectorInit(edges);
    int startNode = FindStartNode();
    answer.push_back(startNode);
    
    for(int i = 0; i < node_out[startNode].size(); i++)
        FindGraph(node_out[startNode][i]);
    
    answer.push_back(graph_donut);
    answer.push_back(graph_bar);
    answer.push_back(graph_eight);
    
    return answer;
}

void VectorInit(vector<vector<int>> edges)
{
    for(int i = 0; i < edges.size(); i++)
    {
        int StartNode = edges[i][0];
        int EndNode = edges[i][1];
        node_in[EndNode].push_back(StartNode);
        node_out[StartNode].push_back(EndNode);
    }
}

int FindStartNode()
{
    for(int i = 1; i < MAX; i++)
    {
        if(node_out[i].size() >= 2 && node_in[i].size() == 0)
            return i;
    }
}

void FindGraph(int Node)
{
    s.push(Node);
    while(!s.empty())
    {
        int CurrentNode = s.top();
        s.pop();
        if(node_out[CurrentNode].size() >= 2)
        {
            graph_eight++;
            return;
        }
        if(node_out[CurrentNode].size() == 0)
        {
            graph_bar++;
            return;
        }
        for(int i = 0; i < node_out[CurrentNode].size(); i++)
        {
            int NextNode = node_out[CurrentNode][i];
            if(NextNode == Node)
            {
                graph_donut++;
                return;
            }
            else
            {
                s.push(NextNode);
            }
        }
    }
}