#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 5001

using namespace std;
int n, temp;
vector<int> v;

void init();
void selectLiquid();

int main()
{
    init();
    selectLiquid();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
}

void selectLiquid()
{
    long long minVal = 3'000'000'001;
    int minLiquids[3] = {0, 0, 0};
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n - 1; j++)
            {
                int left = j + 1;
                int right = n - 1;
                int mid = 0;
                long long currentVal = v[i] + v[j];
                while(left <= right)
                {
                    mid = (left + right) / 2;
                    if(v[mid] + currentVal < 0)
                        left = mid + 1;
                    else if(v[mid] + currentVal > 0)
                        right = mid - 1;
                    else
                        break;
                }
                if(currentVal + v[mid] == 0)
                {
                    cout << v[i] << ' ' << v[j] << ' ' << v[mid];
                    return;
                }
                else if(right == j)
                    mid = left;
                else if(left == n)
                    mid = right;
                else if(abs(currentVal + v[left]) < abs(currentVal + v[right]))
                    mid = left;
                else
                    mid = right;
                if(minVal > abs(currentVal + v[mid]))
                {
                    minVal = abs(currentVal + v[mid]);
                    minLiquids[0] = v[i];
                    minLiquids[1] = v[j];
                    minLiquids[2] = v[mid];
                }
            }
    for(int i = 0; i < 3; i++)
        cout << minLiquids[i] << ' ';
}