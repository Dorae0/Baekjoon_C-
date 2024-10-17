#include <iostream>

using namespace std;

struct Node
{
private:
    Node* prev;
    Node* left;
    Node* right;
    char nodeName;
    int nodeNum;

public:
    Node();
    Node(char c);
    void SetLeft(Node* l) {left = l;};
    void SetRight(Node* r) {right = r;};
    void SetPrev(Node* p) {prev = p;};
    Node* GetLeft() {return left;};
    Node* GetRight() {return right;};
    Node* GetPrev() {return prev;};
    char GetnodeName() {return nodeName;};
    int GetnodeNum() {return nodeNum;};
};

Node::Node()
{
    prev = nullptr;
    left = nullptr;
    right = nullptr;
    nodeName = 'x';
    nodeNum = -1;
}

Node::Node(char c)
{
    prev = nullptr;
    left = nullptr;
    right = nullptr;
    nodeName = c;
    nodeNum = c - 'A';
}

Node* nodes[26];
bool visited[26];
int n;
char a, b, c;
string ans;
void Init();
void PreOrder(int CurrentNode);
void InOrder(int CurrentNode);
void PostOrder(int CurrentNode);

int main()
{
    Init();
    PreOrder(0);
    cout << ans << '\n';
    ans = "";
    InOrder(0);
    cout << ans << '\n';
    ans = "";
    PostOrder(0);
    cout << ans << '\n';
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        nodes[i] = new Node('A' + i);
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        int NodeIndex = a - 'A';
        int LeftIndex = -1;
        int RightIndex = -1;
        if(b != '.')
            LeftIndex = b - 'A';
        if(c != '.')
            RightIndex = c - 'A';
        if(LeftIndex >= 0)
        {
            nodes[NodeIndex]->SetLeft(nodes[LeftIndex]);
            nodes[LeftIndex]->SetPrev(nodes[NodeIndex]);
        }
        if(RightIndex >= 0)
        {
            nodes[NodeIndex]->SetRight(nodes[RightIndex]);
            nodes[RightIndex]->SetPrev(nodes[NodeIndex]);
        }
    }
}

void PreOrder(int CurrentNode)
{
    Node* LeftNode = nodes[CurrentNode]->GetLeft();
    Node* RightNode = nodes[CurrentNode]->GetRight();

    ans.push_back(CurrentNode + 'A');
    if(LeftNode)
        PreOrder(LeftNode->GetnodeNum());
    if(RightNode)
        PreOrder(RightNode->GetnodeNum());
}

void InOrder(int CurrentNode)
{ 
    Node* LeftNode = nodes[CurrentNode]->GetLeft();
    Node* RightNode = nodes[CurrentNode]->GetRight();

    if(LeftNode)
        InOrder(LeftNode->GetnodeNum());
    ans.push_back(CurrentNode + 'A');
    if(RightNode)
        InOrder(RightNode->GetnodeNum());
}

void PostOrder(int CurrentNode)
{ 
    Node* LeftNode = nodes[CurrentNode]->GetLeft();
    Node* RightNode = nodes[CurrentNode]->GetRight();

    if(LeftNode)
        PostOrder(LeftNode->GetnodeNum());
    if(RightNode)
        PostOrder(RightNode->GetnodeNum());
    ans.push_back(CurrentNode + 'A');
}