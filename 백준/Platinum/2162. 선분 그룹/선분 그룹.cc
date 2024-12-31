#include <iostream>
#include <vector>
#include <map>

#define START 0
#define END 1
#define X 0
#define Y 1
#define MAX 3001

using namespace std;
using pii = pair<int, int>;

int n, parent[MAX], temp_pair[2];
struct line {
    pii point[2];
};
line temp;
vector<line> vec;
map<int, int> mp;

void init();
int ccw(int p[2], int q[2], int r[2]);
bool lineCross(line l, line m);
void lineGroup();
int Find(int x);
void Union(int x, int y);
int size(int x);

int main()
{
    init();
    lineGroup();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int ccw(pii p, pii q, pii r)
{
    if ((p.first * q.second + q.first * r.second + r.first * p.second) - (p.second * q.first + q.second * r.first + r.second * p.first) < 0)
        return -1;
    else if ((p.first * q.second + q.first * r.second + r.first * p.second) - (p.second * q.first + q.second * r.first + r.second * p.first) > 0)
        return 1;
    else
        return 0;
}

bool lineCross(line l, line m)
{
    int valueL = ccw(l.point[0], l.point[1], m.point[0]) * ccw(l.point[0], l.point[1], m.point[1]);
    int valueM = ccw(m.point[0], m.point[1], l.point[0]) * ccw(m.point[0], m.point[1], l.point[1]);
    if (valueL == 0 && valueM == 0)
    {
        if (l.point[0] > l.point[1]) swap(l.point[0], l.point[1]);
        if (m.point[0] > m.point[1]) swap(m.point[0], m.point[1]);
        return m.point[0] <= l.point[1] && l.point[0] <= m.point[1];
    }
    return valueL <= 0 && valueM <= 0;
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return;//이미 같은 집합이므로 무시
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

void lineGroup()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
                cin >> temp_pair[k];
            temp.point[j] = {temp_pair[0], temp_pair[1]};
        }
        for (int j = 0; j < vec.size(); j++)
        {
            line currentLine = vec[j];
            if (lineCross(temp, currentLine))
                Union(i, j);
        }
        vec.push_back(temp);
    }
    for (int i = 0; i < n; i++)
        mp[Find(i)]++;
    cout << mp.size() << '\n';
    int max_val = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
        max_val = max(max_val, it->second);
    cout << max_val;
}