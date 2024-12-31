#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k, temp, num;
vector<int> parent;
vector<int> v;

void init();
int find(int num);
void merge(int x, int y);
void cardGame();

int main()
{
	init();
	cardGame();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		v.push_back(temp);
		parent.push_back(i);
	}
	sort(v.begin(), v.end());
}

int find(int num)
{
	if (parent[num] == num) return num;
	else return find(parent[num]);
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return;
	parent[x] = y;
}

void cardGame()
{
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		int upperIdx = find(upper_bound(v.begin(), v.end(), num) - v.begin());
		cout << v[upperIdx] << '\n';
		merge(upperIdx, upperIdx + 1);
	}
}