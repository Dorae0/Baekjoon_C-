#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
string s;
bool ans;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    while(1)
    {
        ans = true;
        getline(cin, s);
        if(s.compare(".") == 0)
            break;

        while(!st.empty())
            st.pop();

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == '[')
                st.push('[');
            else if(s[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    ans = false;
                    break;
                }
                else
                    st.pop();
            }
            else if(s[i] == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    ans = false;
                    break;
                }
                else
                    st.pop();
            }
            else if(s[i] == '.')
                break;
        }
        if(ans && st.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}