#include <iostream>
#include <vector>
#include <cmath>
#define MAX 10000

using namespace std;
int n;
double tempX, tempY;
vector<pair<double, double>> points;

void init();
double shoelace();

int main()
{
    init();
    cout << fixed;
    cout.precision(1);
    cout << shoelace();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tempX >> tempY;
        points.push_back({tempX, tempY});
    }
    points.push_back({points[0].first, points[0].second});
}

double shoelace()
{
    double ans = 0;
    for(int i = 0; i < points.size() - 1; i++)
    {
        ans += points[i].first * points[i + 1].second;
        ans -= points[i].second * points[i + 1].first;
    }
    return round(abs(ans) * 10) / 20;
}