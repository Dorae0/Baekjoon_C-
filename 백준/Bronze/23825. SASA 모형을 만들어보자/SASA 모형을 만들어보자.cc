#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

void Init();

int main()
{
    Init();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cout << min(n, m) / 2;
}