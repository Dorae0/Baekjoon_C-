#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int Index;
    Node* Prev;
    vector<Node*> Next;
    Node(int Number, Node* Node){
        Index = Number;
        Prev = Node;
    }
    void insert(int Number){
        this->Next.push_back(new Node(Number, this));
    }
};

int C, M;
bool IsValid = true;
void Input();
void Print(Node* Root);
void DFS(Node* Root, int Number);

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    Input();
}

void Input()
{
    Node* Root = new Node(0, nullptr);
    cin >> C;
    for(int i = 0; i < C; i++)
    {
        cin >> M;
        if(IsValid)
        {
            if(Root->Index == M - 1)
            {
                Root->insert(M);
            }
            else if(Root->Index == M - 2)
            {
                if(Root->Next.empty())
                    IsValid = false;
                else
                {
                    Root = Root->Next.back();
                    Root->insert(M);
                }
            }
            else if(Root->Index >= M)
            {
                int Sub = Root->Index - M + 1;
                for(int i = 0; i < Sub; i++)
                    Root = Root->Prev;
                Root->insert(M);
            }
            else
                IsValid = false;
        }
    }
    while(1)
    {
        if(Root->Index == 0)
            break;
        else
            Root = Root->Prev;
    }
    Print(Root);
}

void Print(Node* Root)
{
    if(!IsValid)
        cout << -1;
    else
        DFS(Root, 1);
}

void DFS(Node* Root, int Number)
{
    for(int i = 0; i < Root->Next.size(); i++)
    {
        cout << Number++ << ' ';
        DFS(Root->Next[i], 1);
    }
}