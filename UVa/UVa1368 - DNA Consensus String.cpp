#include <stdio.h>
#include <string.h>
#include <ctype.h>

char DNA[55][1005];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas,n,m;
    int ce; // consensus error
    int cnt[4];
    const char LETTER[5] = "ACGT";
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &m,&n);
        for(int i=0; i<m; i++)
            scanf("%s", DNA[i]);
        ce = 0;
        for(int j=0; j<n; j++)
        {
            memset(cnt, 0, sizeof(cnt));
            for(int i=0; i<m; i++)
            {
                if(DNA[i][j] == 'A') cnt[0]++;
                else if(DNA[i][j] == 'C') cnt[1]++;
                else if(DNA[i][j] == 'G') cnt[2]++;
                else cnt[3]++;
            }
            int biggest, mx = 0;
            for(int k=0; k<4; k++)
            {
                if(cnt[k] > 0 && cnt[k] > mx)
                {
                    mx = cnt[k];
                    biggest = k;
                }
            }
            ce += m - mx;
            putchar(LETTER[biggest]);
        }
        printf("\n%d\n", ce);
    }
    return 0;
}
