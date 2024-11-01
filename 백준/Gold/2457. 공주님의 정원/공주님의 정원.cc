#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int n;
int sM, sD, eM, eD;

struct Flower{
    int startMonth;
    int startDate;
    int endMonth;
    int endDate;
};

int compare(Flower a, Flower b)
{
    if(a.startMonth == b.startMonth)
    {
        if(a.startDate == b.startDate)
        {
            if(a.endMonth == b.endMonth)
                return a.endDate < b.endDate;
            else
                return a.endMonth < b.endMonth;
        }
        else
            return a.startDate < b.startDate;
    }
    else return a.startMonth < b.startMonth;
};

int compareByEndDate(Flower a, Flower b)
{
    if(a.endMonth == b.endMonth)
        return a.endDate > b.endDate;
    else return a.endMonth > b.endMonth;
};

Flower flowerInfo[100000];

void Init();
void Sort();
int Greedy();

int main()
{
    Init();
    Sort();
    cout << Greedy();
}

void Init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sM >> sD >> eM >> eD;
        if(sM != eM || sD != eD)
        {
            flowerInfo[i].startMonth = sM;
            flowerInfo[i].startDate = sD;
            flowerInfo[i].endMonth = eM;
            flowerInfo[i].endDate = eD;
        }
    }
}

void Sort()
{
    sort(flowerInfo, flowerInfo + n, compare);
}

int Greedy()
{
    if(flowerInfo[0].startMonth > 3)
        return 0;
    else if(flowerInfo[0].startMonth == 3 && flowerInfo[0].startDate > 1)
        return 0;
    int EndMonth = 3;
    int EndDate = 1;
    int StartIdx = 0;
    int Idx = 0;
    int Count = 0;
    while(Idx < n)
    {
        int CurrentStartMonth = flowerInfo[Idx].startMonth;
        int CurrentStartDate = flowerInfo[Idx].startDate;
        int CurrentEndMonth = flowerInfo[Idx].endMonth;
        int CurrentEndDate = flowerInfo[Idx].endDate;
        if(EndMonth > CurrentStartMonth || (EndMonth == CurrentStartMonth && EndDate >= CurrentStartDate))
        {
            Idx++;
            continue;
        }
        else
        {
            sort(flowerInfo + StartIdx, flowerInfo + Idx, compareByEndDate);
            if(flowerInfo[StartIdx].startMonth > EndMonth || (flowerInfo[StartIdx].startMonth == EndMonth && flowerInfo[StartIdx].startDate > EndDate))
                return 0;
            EndMonth = flowerInfo[StartIdx].endMonth;
            EndDate = flowerInfo[StartIdx].endDate;
            StartIdx = Idx;
            Count++;
            if(EndMonth == 12)
                return Count;
        }
    }
    sort(flowerInfo + StartIdx, flowerInfo + Idx, compareByEndDate);
    EndMonth = flowerInfo[StartIdx].endMonth;
    EndDate = flowerInfo[StartIdx].endDate;
    StartIdx = Idx;
    Count++;
    if(EndMonth == 12)
        return Count;
    return 0;
}