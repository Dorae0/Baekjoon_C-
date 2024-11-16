#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        if(t == 0)
        {
            if(pq.empty())
                cout << '0' << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(t);
    }
    return 0;
}