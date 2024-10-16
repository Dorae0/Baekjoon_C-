#include <iostream>

using namespace std;

long long a, b, c, k;
long long ans = 1;

long long Calculate(long long b);

int main()
{   
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << Calculate(b);
}

long long Calculate(long long b)
{
    if(b == 0) return 1;
    if(b == 1) return a % c;

    k = Calculate(b / 2) % c;
    if(b % 2 == 0) return k * k % c;
    else return k * k % c * a % c;
}
