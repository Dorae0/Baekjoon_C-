#include <iostream>
#include <vector>

using namespace std;
int temp, total;
vector<int> v;

int main()
{
    for(int i = 0; i < 9; i++)
    {
        cin >> temp;
        total += temp;
        v.push_back(temp);
    }
    for(int i = 0; i < 9; i++)
        for(int j = i + 1; j < 9; j++)
            if(total - v[i] - v[j] == 100)
            {
                for(int k = 0; k < 9; k++)
                {
                    if(k == i || k == j) continue;
                    cout << v[k] << '\n';
                }
                return 0;
            }
}