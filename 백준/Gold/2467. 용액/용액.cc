#include <iostream>
#include <vector>

using namespace std;
int n, temp;
int ansLeft, ansRight;
int ans = ~0U >> 1;
vector<int> liquids;

void init();
void selectLiquids();

int main()
{
    init();
    selectLiquids();
    cout << ansLeft << ' ' << ansRight;
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        liquids.push_back(temp);
    }
}

void selectLiquids()
{
    for(int i = 0; i < n; i++)
    {
        int currentNum = i;
        int left = 0;
        int right = n - 1;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(liquids[mid] + liquids[currentNum] > 0)
                right = mid - 1;
            else if(liquids[mid] + liquids[currentNum] < 0)
                left = mid + 1;
            else
                break;
        }
        for(int j = mid - 1; j < mid + 2; j++)
        {
            if(j < 0 || j >= n || j == currentNum)
                continue;
            if(ans > abs(liquids[j] + liquids[currentNum]))
            {
                ans = abs(liquids[j] + liquids[currentNum]);
                ansLeft = liquids[min(currentNum, j)];
                ansRight = liquids[max(currentNum, j)];
            }
        }
    }
}