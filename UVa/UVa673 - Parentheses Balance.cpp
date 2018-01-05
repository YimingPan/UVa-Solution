#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

bool is_match(char ch, stack<char> &st)
{
    if((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '['))
    {
        st.pop();
        return true;
    }
    else
        return false;
}

int main()
{
    int n;
    char str[200];
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        gets(str); // deal with empty string
        stack<char> ms;
        bool flag = 1;
        for(int i=0; str[i]; i++)
        {
            if(str[i] == '(' || str[i] == '[')
                ms.push(str[i]);
            else if(ms.empty() || !is_match(str[i], ms))
            {
                flag = 0;
                break;
            }
        }
        if(flag && ms.empty()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
