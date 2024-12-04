#include <iostream>
#include <string>

using namespace std;
string s, p;

void init();
int maxLength(int idx);
void minCopy();

int main()
{
    init();
    minCopy();
}

void init()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> p;
}

int maxLength(int idx)
{
    int initialIdx = idx;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == p[idx])
        {
            int currentCount = 1;
            int s_idx = i;
            while(++idx < p.length())
            {
                if(s[++s_idx] != p[idx])
                    break;
                currentCount++;
            }
            ans = max(ans, currentCount);
            i += currentCount;
            idx = initialIdx;
        }
    }
    return ans;
}

void minCopy()
{
    int p_index = 0;
    int count = 0;
    while(p_index < p.length())
    {
        p_index += maxLength(p_index);
        count++;
    }
    cout << count;
}