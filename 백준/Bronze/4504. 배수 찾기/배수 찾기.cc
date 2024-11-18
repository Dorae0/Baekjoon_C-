#include <iostream>

using namespace std;
int n;

void Init();
void IsMultiple();

int main()
{
    Init();
    IsMultiple();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
}

void IsMultiple()
{
    int CurrentX;
    while(1)
    {
        cin >> CurrentX;
        if(!CurrentX) break;
        cout << CurrentX << " is ";
        if(CurrentX % n) cout << "NOT ";
        cout << "a multiple of " << n << '.' << '\n';
    }
}