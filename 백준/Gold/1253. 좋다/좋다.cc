#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, temp;
vector<int> numbers;

void Init();
int Good();
bool Binary_Search(int Index);

int main()
{
    Init();
    cout << Good();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
}

int Good()
{
    int ans = 0;
    if(numbers.size() <= 2)
        return 0;
    for(int i = 0; i < numbers.size(); i++)
        if(Binary_Search(i))
            ans++;
    return ans;
}

bool Binary_Search(int Index)
{
    int lowIndex = 0;
    int highIndex = n - 1;
    while(lowIndex < highIndex)
    {
        if(numbers[lowIndex] + numbers[highIndex] > numbers[Index])
            highIndex--;
        else if(numbers[lowIndex] + numbers[highIndex] < numbers[Index])
            lowIndex++;
        else if(Index != lowIndex && Index != highIndex)            
            return true;

        if(Index == lowIndex)
            lowIndex++;
        if(Index == highIndex)
            highIndex--;        
    }
    return false;
}