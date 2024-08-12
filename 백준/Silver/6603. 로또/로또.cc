#include <iostream>
#include <algorithm>
#define MAX 49
#define PRINT_NUM 6
using namespace std;

int n;
int arr[MAX], backtracking_arr[MAX];
bool visited[MAX];

void backtracking(int cnt, int currentNum);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		backtracking(0, 0);
		printf("\n");
	}

	return 0;
}

void backtracking(int cnt, int currentNum)
{
	if (cnt == PRINT_NUM)
	{
		for (int i = 0; i < PRINT_NUM; i++)
			//cout << backtracking_arr[i] << ' ';
			printf("%d ", backtracking_arr[i]);
		//cout << endl;
		printf("\n");
		return;
	}
	for (int i = currentNum; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			backtracking_arr[cnt] = arr[i];
			backtracking(cnt + 1, i);
			visited[i] = false;
		}
	}
}