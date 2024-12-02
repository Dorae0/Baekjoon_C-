#include <iostream>

using namespace std;
long long n;

void init();
void primeFactorization();

int main()
{
    init();
    primeFactorization();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void primeFactorization()
{
    int ans = 0;
    for(long long i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            ans++;
            n /= i;
        }
    }
    if(n > 1)
        ans++;
    if(ans == 2)
        cout << "cubelover";
    else
        cout << "koosaga";
}