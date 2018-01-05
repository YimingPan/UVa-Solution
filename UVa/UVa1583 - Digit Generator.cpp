#include <stdio.h>
#include <string.h>

int g[110000];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int T, N;
    for(int i=1; i<=100000; i++)
    {
        int num = i, s = i;
        while(num)
        {
            s += num%10;
            num /= 10;
        }
        if(!g[s]) g[s] = i;
    }
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        printf("%d\n", g[N]);
    }
    return 0;
}
