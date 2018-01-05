#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas;
    bool first = 1;
    char str[100];
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", str);
        int len = strlen(str);
        int ans = 0;
        for(int k=1; k<=len; k++)
        {
            if(len % k != 0) continue;
            bool is_equal = 1;
            for(int i=k; i<len; i+=k)
            {
                for(int j=0; j<k; j++)
                {
                    if(str[j] != str[i+j])
                    {
                        is_equal = 0;
                        break;
                    }
                }
            }
            if(is_equal)
            {
                ans = k;
                break;
            }
        }
        if(!first) printf("\n");
        first = 0;
        printf("%d\n", ans);
    }
    return 0;
}
