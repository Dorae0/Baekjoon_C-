#include <iostream>
#include <vector>

using namespace std;
int n, temp, ans = 0;
vector<int> v;
int check();

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << check();
    return 0;
}

int check()
{
    int maxval = 0;
    int start_iter = 0, end_iter = 0;
    int count[9] = { 0, };

    while (end_iter < v.size())
    {
        count[v[end_iter++] - 1]++;
        int countval = 0;

        for (int i = 0; i < 9; i++)
            if (count[i] != 0) countval++;

        if (countval >= 3)
            count[v[start_iter++] - 1]--;
        else
            maxval = max(maxval, end_iter - start_iter);
    }

    return maxval;
}