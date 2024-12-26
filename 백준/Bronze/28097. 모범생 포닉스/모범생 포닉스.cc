#include <iostream>

using namespace std;
int n, temp, ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        ans += temp;
    }
    ans += (n - 1) * 8;
    cout << ans / 24 << ' ' << ans % 24;
}