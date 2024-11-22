#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101

using namespace std;

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if(a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};

int n, m, tmp;
vector<int> ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq_a;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq_b;
vector<pair<int, int>> temp;

void Init();
void Latest_Dict();

int main()
{
    Init();
    Latest_Dict();
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        pq_a.push({tmp, i});
    }	
    cin >> m;
    for(int i = 0; i < m; i++)
	{
        cin >> tmp;
        pq_b.push({tmp, i});
    }
}

void Latest_Dict()
{
	int Idx_A = 0;
	int Idx_B = 0;

	while(!pq_a.empty())
	{
		int CurrentVal = pq_a.top().first;
		int CurrentIdx = pq_a.top().second;
		pq_a.pop();
		if(CurrentIdx < Idx_A)
			continue;
		while(!pq_b.empty())
		{
			if(pq_b.top().second < Idx_B)
			{
				pq_b.pop();
				continue;
			}
			if(CurrentVal == pq_b.top().first)
			{
				Idx_A = CurrentIdx;
				Idx_B = pq_b.top().second;
				ans.push_back(CurrentVal);
				pq_b.pop();
				break;
			}
			else if(CurrentVal < pq_b.top().first)
			{
				temp.push_back(pq_b.top());
				pq_b.pop();
			}
			else
			{
				for(int i = 0; i < temp.size(); i++)
				{
					pq_b.push(temp.back());
					temp.pop_back();
				}
				break;
			}
		}
	}
}