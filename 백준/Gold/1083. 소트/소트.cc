#include <iostream>
#define MAX 50

using namespace std;
int n, s;
int numbers[MAX];
void Init();
void SortSolve();
void Print();

int main()
{
    Init();
    SortSolve();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    cin >> s;
}

void SortSolve()
{
    int CurrentChanged = 0;
    for(int i = 0; i < n; i++)
    {
        if(CurrentChanged > s)
            break;
        int CurrentVal = numbers[i];
        int CurrentIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(CurrentChanged + (j - i - 1) >= s)
                break;
            if(CurrentVal < numbers[j])
            {
                CurrentVal = numbers[j];
                CurrentIndex = j;
            }
        }
        for(int j = CurrentIndex; j > i; j--)
            swap(numbers[j], numbers[j - 1]);
        CurrentChanged += CurrentIndex - i;
    }
    Print();
}

void Print()
{
    for(int i = 0; i < n; i++)
        cout << numbers[i] << ' ';
}