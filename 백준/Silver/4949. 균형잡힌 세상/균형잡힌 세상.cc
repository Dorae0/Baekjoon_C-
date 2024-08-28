#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
string s;
bool ans;

int main()
{
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
        if(ans && st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}