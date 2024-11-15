#include <iostream>
#include <queue>

using namespace std;
int n, type, student;
void Init();
void Solve();

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void Solve()
{
    queue<int> q;
    int maxQueue = 0;
    int minStudent = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> student;
            q.push(student);
            if(maxQueue < q.size())
            {
                maxQueue = q.size();
                minStudent = q.back();
            }
            else if(maxQueue == q.size())
            {
                minStudent = min(minStudent, q.back());
            }
        }
        else
        {
            q.pop();
        }
    }
    cout << maxQueue << ' ' << minStudent;
}