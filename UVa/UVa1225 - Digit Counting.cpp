#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ans[10005][10];

void init()
{
    ans[2][1] = ans[2][2] = 1;
    for(int i=3; i<10000; i++)
    {
        for(int j=0; j<=9; j++) ans[i][j] = ans[i-1][j];
        int x = i;
        while(x)
        {
            ans[i][x%10]++;
            x /= 10;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas,N;
    init();
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &N);
        for(int i=0; i<9; i++)
            printf("%d ", ans[N][i]);
        printf("%d\n", ans[N][9]);
    }
    return 0;
}
