#include <iostream>

using namespace std;
using pii = pair<int, int>;

pii points[3];

void init();
void ccw();

int main()
{
    init();
    ccw();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++)
        cin >> points[i].first >> points[i].second;
}

void ccw()
{
    int ccwVal = (points[0].first * points[1].second + points[1].first * points[2].second + points[2].first * points[0].second) - (points[1].first * points[0].second + points[2].first * points[1].second + points[0].first * points[2].second);
    if(ccwVal > 0)
        cout << 1;
    else if(ccwVal < 0)
        cout << -1;
    else
        cout << 0;
}