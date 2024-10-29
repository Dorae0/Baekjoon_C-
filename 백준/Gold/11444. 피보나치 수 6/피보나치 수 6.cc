#include <iostream>
#include <vector>
#define DIVIDER 1000000007
using namespace std;

long long n;
vector<int> v;
void Init();
void BinArr(long long n);
vector<vector<long long>> MatMul(vector<vector<long long>> a, vector<vector<long long>> b);
int Fibonacci();

int main()
{
    Init();
    cout << Fibonacci();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void BinArr(long long n)
{
    while(n)
    {
        v.push_back(n % 2);
        n /= 2;
    }
}

vector<vector<long long>> MatMul(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> rtn;
    long long CurrentValue;
    rtn.push_back({0, 0}); rtn.push_back({0, 0});
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                rtn[i][j]+= (a[i][k] * b[k][j]) % DIVIDER;
    
    return rtn;
}

int Fibonacci()
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    BinArr(n - 1);
    vector<vector<vector<long long>>> matrixes;
    matrixes.push_back({{1, 1}, {1, 0}});
    for(int i = 1; i < v.size(); i++)
        matrixes.push_back(MatMul(matrixes[i - 1], matrixes[i - 1]));
    vector<vector<long long>> answer = {{1, 0}, {0, 1}};
    for(int i = 0; i < v.size(); i++)
        if(v[i] == 1)
            answer = MatMul(matrixes[i], answer);
    return answer[0][0] % DIVIDER;
}