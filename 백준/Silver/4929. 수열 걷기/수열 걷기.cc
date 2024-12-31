#include <iostream>
#include <vector>

using namespace std;
int l1, l2, temp;

vector<int> v1;
vector<int> v2;

void init();
void vectorInit();
void sequenceWalking();

int main()
{
	init();
	sequenceWalking();
}

void init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
}

void vectorInit()
{
	while (!v1.empty())
		v1.pop_back();
	while (!v2.empty())
		v2.pop_back();
}

void sequenceWalking()
{
	while (1)
	{
		cin >> l1;
		if (!l1) break;
		vectorInit();
		for (int i = 0; i < l1; i++)
		{
			cin >> temp;
			v1.push_back(temp);
		}
		cin >> l2;
		for (int i = 0; i < l2; i++)
		{
			cin >> temp;
			v2.push_back(temp);
		}
		int Idx_1 = 0, Idx_2 = 0;
		int currentSum_1 = 0, currentSum_2 = 0;
		int ans = 0;
		while (Idx_1 < v1.size() && Idx_2 < v2.size())
		{
			if (v1[Idx_1] == v2[Idx_2])
			{
				ans += v1[Idx_1];
				ans += max(currentSum_1, currentSum_2);
				currentSum_1 = 0;
				currentSum_2 = 0;
				Idx_1++;
				Idx_2++;
			}
			else if (v1[Idx_1] < v2[Idx_2])
			{
				currentSum_1 += v1[Idx_1];
				Idx_1++;
			}
			else
			{
				currentSum_2 += v2[Idx_2];
				Idx_2++;
			}
		}
		while (Idx_1 < v1.size())
		{
			currentSum_1 += v1[Idx_1];
			Idx_1++;
		}
		while (Idx_2 < v2.size())
		{
			currentSum_2 += v2[Idx_2];
			Idx_2++;
		}
		ans += max(currentSum_1, currentSum_2);
		cout << ans << '\n';
	}
}