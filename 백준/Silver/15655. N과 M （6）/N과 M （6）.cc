#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX], backtracking_arr[MAX];
bool visited[MAX];

void backtracking(int cnt, int currentNum);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	backtracking(0, 0);

	return 0;
}

void backtracking(int cnt, int currentNum)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			//cout << backtracking_arr[i] << ' ';
			printf("%d ", backtracking_arr[i]);
		//cout << endl;
		printf("\n");
		return;
	}
	for (int i = currentNum; i < n; i++)
	{
		if (!visited[i] == true)
		{
			visited[i] = true;
			backtracking_arr[cnt] = arr[i];
			backtracking(cnt + 1, i);
			visited[i] = false;
		}
	}
}