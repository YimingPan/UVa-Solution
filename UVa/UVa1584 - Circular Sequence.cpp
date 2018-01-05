#include <stdio.h>
#include <string.h>

char str[105];
int ans, len;

void fun(int a, int b)
{
    int cur = b;
    for(int i=1; i<len; i++)
    {
        if(str[a] > str[b])
        {
            ans = cur;
            break;
        }
        else if(str[a] < str[b])
            break;
        else
        {
            a = (a+1)%len;
            b = (b+1)%len;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", str);
        ans = 0;
        len = strlen(str);
        for(int i=1; i<len; i++)
            fun(ans, i);
        //print
        for(int i=0; i<len; i++, ans=(ans+1)%len)
            putchar(str[ans]);
        printf("\n");
    }
    return 0;
}
