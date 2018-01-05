#include <stdio.h>
#include <string.h>
#include <ctype.h>

double mass(char c)
{
    if(c == 'C') return 12.01;
    if(c == 'H') return 1.008;
    if(c == 'O') return 16.00;
    return 14.01;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas;
    char str[85];
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%s", str);
        int p = 0;
        double sum = 0.0;
        double m;
        while(str[p] != '\0')
        {
            m = mass(str[p++]);
            if(str[p] < '0' || str[p] > '9')
                sum += m;
            else
            {
                int n = 0;
                while(str[p] >= '0' && str[p] <= '9')
                {
                    n = n*10 + (str[p] - '0');
                    p++;
                }
                sum += m*n;
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}
