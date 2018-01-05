#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <stack>

using namespace std;

struct Matrix
{
    int r, c;
    Matrix(int r=0, int c=0):r(r), c(c) {}
}m[26];

stack<Matrix> st;

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    char str[100];

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int k;
        scanf("%s", str);
        k = str[0] - 'A';
        scanf("%d %d\n", &m[k].r, &m[k].c);
    }
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        int ans = 0;
        bool error = false;
        for (int i=0; i<len; i++)
        {
            if (isalpha(str[i]))
                st.push(m[str[i] - 'A']);
            else if (str[i] == ')')
            {
                Matrix m2 = st.top(); st.pop();
                Matrix m1 = st.top(); st.pop();
                if (m1.c != m2.r)
                {
                    error = true;
                    break;
                }
                ans += m1.r*m1.c*m2.c;
                st.push(Matrix(m1.r, m2.c));
            }
        }
        if (error)
            puts("error");
        else
            printf("%d\n", ans);
    }
    return 0;
}
