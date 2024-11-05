#include <iostream>

using namespace std;
int n;
char stars[3072][6143];

void Init();
void Stars_Recursion(int PosX, int PosY, int size);
void Print();

int main()
{
    Init();
    Stars_Recursion(n - 1, 0, n);
    Print();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2 * n - 1; j++)
            stars[i][j] = ' '; 
}

void Stars_Recursion(int PosX, int PosY, int size)
{
    if(size == 3)
    {
        stars[PosY][PosX] = '*';
        for(int i = -1; i < 2; i++)
            stars[PosY + 1][PosX + i] = '*';
        for(int i = -2; i < 3; i++)
            stars[PosY + 2][PosX + i] = '*';
        stars[PosY + 1][PosX] = ' ';
    }
    else
    {
        Stars_Recursion(PosX, PosY, size / 2);
        Stars_Recursion(PosX - size / 2, PosY + size / 2 ,size / 2);
        Stars_Recursion(PosX + size / 2, PosY + size / 2 ,size / 2);
    }
}

void Print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 * n - 1; j++)
            cout << stars[i][j];
        cout << '\n';
    }
}