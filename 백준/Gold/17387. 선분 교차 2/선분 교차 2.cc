#include <iostream>

using namespace std;
using pll = pair<long long, long long>;
pll points[4];

void init();
void crossLine();

int main()
{
    init();
    crossLine();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 4; i++)
        cin >> points[i].first >> points[i].second;
}

void crossLine()
{
    long long firstDirection = (points[0].first * points[1].second + points[1].first * points[2].second + points[2].first * points[0].second) - (points[1].first * points[0].second + points[2].first * points[1].second + points[0].first * points[2].second);
    long long secondDirection = (points[0].first * points[1].second + points[1].first * points[3].second + points[3].first * points[0].second) - (points[1].first * points[0].second + points[3].first * points[1].second + points[0].first * points[3].second);
    if(firstDirection > 0) firstDirection = 1;
    else if(firstDirection < 0) firstDirection = -1;
    else firstDirection = 0;

    long long thirdDirection = (points[2].first * points[3].second + points[3].first * points[0].second + points[0].first * points[2].second) - (points[3].first * points[2].second + points[0].first * points[3].second + points[2].first * points[0].second);
    long long fourthDirection = (points[2].first * points[3].second + points[3].first * points[1].second + points[1].first * points[2].second) - (points[3].first * points[2].second + points[1].first * points[3].second + points[2].first * points[1].second);
    if(thirdDirection > 0) thirdDirection = 1;
    else if(thirdDirection < 0) thirdDirection = -1;
    else thirdDirection = 0;

    if(firstDirection * secondDirection == 0 && thirdDirection * fourthDirection == 0)
    {
        if(points[0] > points[1]) swap(points[0], points[1]);
        if(points[2] > points[3]) swap(points[2], points[3]);
        if(points[2] <= points[1] && points[0] <= points[3])
            cout << 1;
        else
            cout << 0;
        return;
    }

    if(firstDirection * secondDirection <= 0 && thirdDirection * fourthDirection <= 0) cout << 1;
    else cout << 0;
}