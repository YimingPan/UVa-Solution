#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int tree[(1<<8)+5];

int visitTree(char s[], int order[], int n)
{
    int u = 1;
    for(int i=0; i<n; i++)
    {
        int c = order[i]-1;
        u = (s[c] == '0') ? u*2 : u*2+1;
    }
    return tree[u];
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    int n, m, cas = 1;
    int order[8];
    char s[(1<<7)+5];
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s", s);
            order[i] = s[1] - '0';
        }
        scanf("%s", s);
        memset(tree, 0, sizeof(tree));
        for(int i=(1<<n), j=0; i<(1<<(n+1)); i++, j++)
        {
            tree[i] = s[j] - '0';
        }

        scanf("%d", &m);
        printf("S-Tree #%d:\n", cas++);
        while(m--)
        {
            scanf("%s", s);
            printf("%d", visitTree(s, order, n));
        }
        printf("\n\n");
    }

    return 0;
}
