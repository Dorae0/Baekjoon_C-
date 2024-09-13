#include <iostream>
#include <queue>
#include <string>
#define MAX 10000

using namespace std;

int n, destination;
long long t;
queue<pair<int,string>> q;
bool visited[MAX];

void InitializeVisited();
void InitializeQueue();
string AddChar(string s, char c);
int D(int n);
int S(int n);
int L(int n);
int R(int n);
void bfs();

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    for(long long i = 0; i < t; i++)
    {
        cin >> n >> destination;
        InitializeVisited();
        InitializeQueue();
        bfs();
    }
}

void InitializeVisited()
{
    for(int i = 0; i < MAX; i++)
        visited[i] = false;
}

void InitializeQueue()
{
    while(!q.empty())
        q.pop();
}

string AddChar(string str, char c)
{
    str.push_back(c);
    return str;
}

int D(int n)
{
    return (n * 2) % 10000;
}

int S(int n)
{
    n--;
    if(n < 0) n += 10000;
    return n;
}

int L(int n)
{
    int n1 = n / 1000;
    int n2 = (n % 1000) / 100;
    int n3 = (n % 100) / 10;
    int n4 = (n % 10);
    return ((n2 * 10 + n3) * 10 + n4)* 10 + n1;
}

int R(int n)
{
    int n1 = n / 1000;
    int n2 = (n % 1000) / 100;
    int n3 = (n % 100) / 10;
    int n4 = (n % 10);
    return ((n4 * 10 + n1) * 10 + n2)* 10 + n3;
}

void bfs()
{
    q.push({n, ""});
    while(!q.empty())
    {
        int currentNum = q.front().first;
        string currentString = q.front().second;
        q.pop();
        if(currentNum == destination)
        {
            cout << currentString << '\n';
            return;
        }
        int dnum = D(currentNum);
        int snum = S(currentNum);
        int lnum = L(currentNum);
        int rnum = R(currentNum);
        if(!visited[dnum])
        {
            visited[dnum] = true;
            q.push({dnum, AddChar(currentString, 'D')});
        }
        if(!visited[snum])
        {
            visited[snum] = true;
            q.push({snum, AddChar(currentString, 'S')});
        }
        if(!visited[lnum])
        {
            visited[lnum] = true;
            q.push({lnum, AddChar(currentString, 'L')});
        }
        if(!visited[rnum])
        {
            visited[rnum] = true;
            q.push({rnum, AddChar(currentString, 'R')});
        }
    }
}