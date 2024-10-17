#include <iostream>

using namespace std;
long long n, t, p;
long long shirts[6];
long long ans;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < 6; i++)
        cin >> shirts[i];
    cin >> t >> p;
    for(int i = 0; i < 6; i++)
        if(shirts[i])
            ans += (shirts[i] - 1) / t + 1;
    cout << ans << '\n' << n / p << ' ' << n % p;
}