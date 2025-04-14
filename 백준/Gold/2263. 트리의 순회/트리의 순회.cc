#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, temp;
vector<int> inOrder, postOrder;

void Init();
void FindPreOrder(int inOrder_s, int inOrder_e, int postOrder_s, int postOrder_e);

int main()
{
	Init();
	FindPreOrder(0, n - 1, 0, n - 1);
}

void Init()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		inOrder.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		postOrder.push_back(temp);
	}
}

void FindPreOrder(int inOrder_s, int inOrder_e, int postOrder_s, int postOrder_e)
{
	int CurrentRoot = postOrder[postOrder_e];
	cout << CurrentRoot << ' ';
	int LeftCount = find(inOrder.begin(), inOrder.end(), CurrentRoot) - inOrder.begin() - inOrder_s;
	int RightCount = inOrder_e - inOrder_s - LeftCount;
	if(LeftCount > 0)
		FindPreOrder(inOrder_s, inOrder_s + LeftCount - 1, postOrder_s, postOrder_s + LeftCount - 1);
	if(RightCount > 0)
		FindPreOrder(inOrder_s + LeftCount + 1, inOrder_e, postOrder_e - RightCount, postOrder_e - 1);
}