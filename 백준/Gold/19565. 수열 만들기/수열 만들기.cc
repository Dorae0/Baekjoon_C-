#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;

void init();
void makeSequence();

int main()
{
    init();
    makeSequence();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void makeSequence()
{
    v.push_back(1);
    v.push_back(1);
    int currentNum = 1;
    while(++currentNum <= n)
    {
        v.push_back(currentNum);
        for(int i = currentNum - 1; i > 0; i--)
        {
            v.push_back(currentNum);
            v.push_back(i);
        }
    }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}
