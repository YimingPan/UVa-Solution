#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int r, c, ncas = 1;
    int num[15][15];
    char mat[15][15];
    while(scanf("%d%d", &r, &c) == 2)
    {
        memset(num, 0, sizeof(num));
        for(int i=0; i<r; i++)
            scanf("%s", mat[i]);
        for(int i=0, cnt=1; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[i][j] == '*') continue;
                if(!i || !j || mat[i][j-1] == '*' || mat[i-1][j] == '*')
                    num[i][j] = cnt++;
            }
        }
        if(ncas > 1) printf("\n");
        printf("puzzle #%d:\nAcross\n", ncas++);
        for(int i=0, j=0; i<r; i++)
        {
            j = 0;
            while(j < c)
            {
                while(j < c && mat[i][j] == '*') j++;
                if(j >= c) break;
                printf("%3d.", num[i][j]);
                while(j < c && mat[i][j] != '*')
                {
                    printf("%c", mat[i][j]);
                    j++;
                }
                printf("\n");
            }
        }
        printf("Down\n");

        for(int k=0; k<r; k++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[k][j] == '*') continue;
                if(!k || mat[k-1][j] == '*')
                {
                    int i = k;
                    printf("%3d.", num[k][j]);
                    while(i < r && mat[i][j] != '*')
                    {
                        printf("%c", mat[i][j]);
                        i++;
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
