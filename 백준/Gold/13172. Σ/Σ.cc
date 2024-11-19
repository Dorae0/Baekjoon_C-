#include <iostream>
#define DIVIDER 1000000007

using namespace std;
long long m, n, s, q;

void Init();
void Solve();
long long Mod_Inverse(long long a, long long b);

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> m;
}

void Solve()
{
    for(int i = 0; i < m; i++)
    {
        cin >> n >> s;
        q += (Mod_Inverse(n, DIVIDER) * s) % DIVIDER;
    }
    cout << q % DIVIDER;
}

long long Mod_Inverse(long long a, long long b)
{
    long long r1 = a, r2 = b, s1 = 1, s2 = 0;
    long long q, r, s;
    long long result;

     while (true) {
        q = r1 / r2;
        r = r1 - (q * r2);
        s = s1 - (q * s2);

        if (r == 0) {
            result = s2;
            break;
        }

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
    }

    while (result <= 0) {
        result += b;
    }

    return result;
}