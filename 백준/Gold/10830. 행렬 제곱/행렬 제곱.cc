#include <iostream>
#include <vector>

using namespace std;
int n, temp;
long long b;
vector<vector<int>> matrix;
vector<vector<vector<int>>> binary_matrix;
vector<int> binary;

void Init();
void Solve();
vector<vector<int>> Matrix_Multiply(vector<vector<int>> a, vector<vector<int>> b);
void Print(vector<vector<int>> v);

int main()
{
    Init();
    Solve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }

    while(b)
    {
        binary.push_back(b % 2);
        b /= 2;
    }

}

vector<vector<int>> Matrix_Multiply(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < n; j++)
        {
            int x = 0;
            for(int k = 0; k < n; k++)
                x += a[i][k] * b[k][j];
            v.push_back(x % 1000);
        }
        ans.push_back(v);
    }
    return ans;
}

void Solve()
{
    binary_matrix.push_back(matrix);
    for(int i = 0; i < binary.size() - 1; i++)
        binary_matrix.push_back(Matrix_Multiply(binary_matrix[i], binary_matrix[i]));

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < n; j++)
        {
            if(i == j) v.push_back(1);
            else v.push_back(0);
        }
        ans.push_back(v);
    }

    for(int i = 0; i < binary.size(); i++)
        if(binary[i])
            ans = Matrix_Multiply(ans, binary_matrix[i]);
    
    Print(ans);
}

void Print(vector<vector<int>> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
}